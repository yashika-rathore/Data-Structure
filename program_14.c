//Name - Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#include <stdlib.h>
typedef struct BST 
{
    int data;
    struct BST *left, *right;
} *Node;
Node createNode(int val) 
{
    Node n = (Node)malloc(sizeof(struct BST));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}
Node insert(Node root, int val) 
{
    Node newNode = createNode(val);
    if (root == NULL)
        return newNode;
    Node curr = root, parent = NULL;
    while (curr != NULL) 
    {
        parent = curr;
        if (val < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}
void inorder(Node root) 
{
    if (root == NULL) 
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(Node root) 
{
    if (root == NULL) 
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node root) {
    if (root == NULL) 
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void bfs(Node root) 
{
    if (root == NULL) 
        return;
    Node q[100];
    int f = 0, r = 0;
    q[r++] = root;
    while (f < r) 
    {
        Node curr = q[f++];
        printf("%d ", curr->data);
        if (curr->left) 
            q[r++] = curr->left;
        if (curr->right) 
            q[r++] = curr->right;
    }
}
void dfs(Node root) 
{
    preorder(root);
}
Node mirror(Node root) 
{
    if (root == NULL) 
        return NULL;
    Node temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
    return root;
}
Node findParent(Node root, int val) 
{
    Node curr = root, parent = NULL;
    while (curr != NULL) 
    {
        if (curr->data == val)
            return parent;
        parent = curr;
        if (val < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return NULL;
}
void printChildren(Node root, int val) 
{
    Node curr = root;
    while (curr != NULL) 
    {
        if (curr->data == val) 
        {
            printf("Children of %d: ", val);
            if (curr->left) 
                printf("%d ", curr->left->data);
            if (curr->right) 
                printf("%d ", curr->right->data);
            if (!curr->left && !curr->right) 
                printf("No children");
            printf("\n");
            return;
        }
        curr = (val < curr->data) ? curr->left : curr->right;
    }
    printf("Node not found.\n");
}
void printSibling(Node root, int val) 
{
    Node parent = findParent(root, val);
    if (!parent) 
    {
        printf("No sibling\n");
        return;
    }
    if (parent->left && parent->left->data == val && parent->right)
        printf("Sibling: %d\n", parent->right->data);
    else if (parent->right && parent->right->data == val && parent->left)
        printf("Sibling: %d\n", parent->left->data);
    else
        printf("No sibling\n");
}
void printGP(Node root, int val) 
{
    Node parent = findParent(root, val);
    if (!parent) 
    { 
        printf("No grandparent\n"); 
        return; 
    }
    Node gp = findParent(root, parent->data);
    if (gp) 
        printf("Grandparent: %d\n", gp->data);
    else 
        printf("No grandparent\n");
}
void printUncle(Node root, int val) 
{
    Node parent = findParent(root, val);
    if (!parent) 
    { 
        printf("No uncle\n"); 
        return; 
    }
    Node gp = findParent(root, parent->data);
    if (!gp) 
    { 
        printf("No uncle\n"); 
        return; 
    }
    if (gp->left && gp->left->data == parent->data && gp->right)
        printf("Uncle: %d\n", gp->right->data);
    else if (gp->right && gp->right->data == parent->data && gp->left)
        printf("Uncle: %d\n", gp->left->data);
    else
        printf("No uncle\n");
}
int main() {
    Node root = NULL;
    int choice, val;
    do {
        printf("\n--- BST MENU ---\n");
        printf("1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n");
        printf("5.BFS\n6.Mirror\n7.Children\n8.Sibling\n");
        printf("9.Parent\n10.Grandparent\n11.Uncle\n12.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2: 
                inorder(root); 
                break;
            case 3: 
                preorder(root); 
                break;
            case 4: 
                postorder(root); 
                break;
            case 5: 
                bfs(root); 
                break;
            case 6:
                mirror(root);
                printf("Tree mirrored.\n");
                break;
            case 7:
                printf("Enter node: ");
                scanf("%d", &val);
                printChildren(root, val);
                break;
            case 8:
                printf("Enter node: ");
                scanf("%d", &val);
                printSibling(root, val);
                break;
            case 9:
                printf("Enter node: ");
                scanf("%d", &val);
                Node p = findParent(root, val);
                if (p) printf("Parent: %d\n", p->data);
                else printf("No parent\n");
                break;
            case 10:
                printf("Enter node: ");
                scanf("%d", &val);
                printGP(root, val);
                break;
            case 11:
                printf("Enter node: ");
                scanf("%d", &val);
                printUncle(root, val);
                break;
            case 12:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 12);
    return 0;
}
