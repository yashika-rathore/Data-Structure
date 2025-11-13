//Name- Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#define MAX 20
int stack[MAX], top = -1;
void push() {
    int val;
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &val);
        stack[++top] = val;
        printf("%d pushed into stack\n", val);
    }
}
void pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}
void peek() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element is %d\n", stack[top]);
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}
int main() {
    int choice;
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                push(); 
                break;
            case 2: 
                pop(); 
                break;
            case 3: 
                peek(); 
                break;
            case 4: 
                display(); 
                break;
            case 5: 
                printf("Exiting...\n");
                break;
            default: 
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
