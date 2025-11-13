//Name- Yashika Rathore Roll no.- CT-A-26
//Two Queues in an Array
#include <stdio.h>
#define MAX 10
int arr[MAX];
int front1 = 0, rear1 = -1;
int front2 = MAX / 2, rear2 = (MAX / 2) - 1;
void enqueue1(int val) {
    if (rear1 == (MAX / 2) - 1) {
        printf("Queue 1 Overflow!\n");
        return;
    }
    arr[++rear1] = val;
    printf("%d added in Queue 1\n", val);
}
void enqueue2(int val) {
    if (rear2 == MAX - 1) {
        printf("Queue 2 Overflow!\n");
        return;
    }
    arr[++rear2] = val;
    printf("%d added in Queue 2\n", val);
}
void dequeue1() {
    if (front1 > rear1) {
        printf("Queue 1 Underflow!\n");
        return;
    }
    printf("%d removed from Queue 1\n", arr[front1++]);
}
void dequeue2() {
    if (front2 > rear2) {
        printf("Queue 2 Underflow!\n");
        return;
    }
    printf("%d removed from Queue 2\n", arr[front2++]);
}
void display() {
    int i;
    printf("\nQueue 1: ");
    if (front1 > rear1)
        printf("Empty");
    else
        for (i = front1; i <= rear1; i++)
            printf("%d ", arr[i]);
    printf("\nQueue 2: ");
    if (front2 > rear2)
        printf("Empty");
    else
        for (i = front2; i <= rear2; i++)
            printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int ch, val;
    do {
        printf("\n1. Enqueue in Queue 1");
        printf("\n2. Enqueue in Queue 2");
        printf("\n3. Dequeue from Queue 1");
        printf("\n4. Dequeue from Queue 2");
        printf("\n5. Display Queues");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue1(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue2(val);
                break;
            case 3:
                dequeue1();
                break;
            case 4:
                dequeue2();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 6);
    return 0;
}
