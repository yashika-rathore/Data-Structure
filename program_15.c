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
void printRange(Node* root, int L, int R) 
{
    Node* stack[100];
    int top = -1;
    Node* curr = root;
    while (curr != NULL || top != -1) 
    {
        while (curr != NULL) 
        {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        if (curr->data >= L && curr->data <= R)
            printf("%d ", curr->data);
        curr = curr->right;
    }
}
int main() 
{
    Node* root = NULL;
    int n, val, L, R;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insertBST(root, val);
    }
    printf("Enter range L R: ");
    scanf("%d %d", &L, &R);
    printf("Values in range [%d, %d]: ", L, R);
    printRange(root, L, R);
    return 0;
}
