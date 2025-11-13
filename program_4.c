//Name- Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#define MAX 10
int arr[MAX];
int top1 = -1;
int top2 = MAX;
void push1(int val) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow!\n");
        return;
    }
    arr[++top1] = val;
    printf("%d pushed to Stack 1\n", val);
}
void push2(int val) {
    if (top2 - 1 == top1) {
        printf("Stack Overflow!\n");
        return;
    }
    arr[--top2] = val;
    printf("%d pushed to Stack 2\n", val);
}
void pop1() {
    if (top1 == -1) {
        printf("Stack 1 Underflow!\n");
        return;
    }
    printf("%d popped from Stack 1\n", arr[top1--]);
}
void pop2() {
    if (top2 == MAX) {
        printf("Stack 2 Underflow!\n");
        return;
    }
    printf("%d popped from Stack 2\n", arr[top2++]);
}
void display() {
    int i;
    printf("\nStack 1: ");
    if (top1 == -1)
        printf("Empty");
    else
        for (i = 0; i <= top1; i++)
            printf("%d ", arr[i]);
    printf("\nStack 2: ");
    if (top2 == MAX)
        printf("Empty");
    else
        for (i = MAX - 1; i >= top2; i--)
            printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int choice, val;
    do {
        printf("\n1. Push in Stack 1");
        printf("\n2. Push in Stack 2");
        printf("\n3. Pop from Stack 1");
        printf("\n4. Pop from Stack 2");
        printf("\n5. Display both Stacks");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push1(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                push2(val);
                break;
            case 3:
                pop1();
                break;
            case 4:
                pop2();
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
    } while (choice != 6);
    return 0;
}
