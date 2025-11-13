//Name- Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#define MAX 20
int queue[MAX];
int front = 0, rear = -1;
void enqueue() {
    int val;
    if (rear == MAX - 1) {
        printf("Queue overflow!\n");
        return;
    }
    printf("Enter value to enqueue: ");
    scanf("%d", &val);
    queue[++rear] = val;
    printf("%d enqueued\n", val);
}
void dequeue() {
    if (front > rear) {
        printf("Queue underflow!\n");
        return;
    }
    printf("%d dequeued\n", queue[front++]);
}
void display() {
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
int main() {
    int choice;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                enqueue(); 
                break;
            case 2: 
                dequeue(); 
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
    return 0;
}

