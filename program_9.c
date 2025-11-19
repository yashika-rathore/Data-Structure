//Name - Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}StackNode;
StackNode* top = NULL;
void push(int val)
{
    StackNode* newNode=(StackNode*)malloc(sizeof(StackNode));
    newNode->data=val;
    newNode->next=top;
    top=newNode;
    printf("%d pushed to stack\n",val);
}
void pop()
{
    if(top==NULL)
    {
        printf("Stack underflow!\n");
        return;
    }
    StackNode* temp=top;
    printf("%d popped from stack\n",top->data);
    top=top->next;
    free(temp);
}
void display()
{
    StackNode* ptr=top;
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main()
{
    int choice, val;
    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val); 
                break;
            case 2: 
                pop(); 
                break;
            case 3: 
                display(); 
                break;
            case 4:
                printf("Exiting...\n"); 
                break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);
}