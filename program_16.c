//Name - Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#include <stdlib.h>
typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;
Node* createNode(int val) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insertBST(Node* root, int val) 
{
    Node* curr = root;
    Node* parent = NULL;
    while (curr != NULL) 
    {
        parent = curr;
        if (val < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    Node* newNode = createNode(val);
    if (parent == NULL)
        return newNode;  
    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}
int findMin(Node* root)
{
    if (root == NULL) 
    {
        printf("Tree is empty!\n");
        return -1;
    }
    Node* curr = root;
    while (curr->left != NULL) 
    {
        curr = curr->left;
    }
    return curr->data;
}
int findMax(Node* root) 
{
    if (root == NULL) 
    {
        printf("Tree is empty!\n");
        return -1;
    }
    Node* curr = root;
    while (curr->right != NULL) 
    {
        curr = curr->right;
    }
    return curr->data;
}
int main() 
{
    Node* root = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insertBST(root, val);
    }
    printf("Minimum value in BST = %d\n", findMin(root));
    printf("Maximum value in BST = %d\n", findMax(root));
    return 0;
}

