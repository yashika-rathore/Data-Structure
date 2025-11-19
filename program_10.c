//Name - Yashika Rathore Roll no. - CT-A-26
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) 
    {
        front = rear = newNode;
    } 
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d\n", value);
}
void dequeue() {
    if (front == NULL) 
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted %d\n", front->data);
    struct Node* temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}
void display() 
{
    struct Node* ptr = front;
    if (ptr == NULL) 
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    while (ptr != NULL) 
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, value;
    do 
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }while(1);
    return 0;
}
