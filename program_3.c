//Name- Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}
char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}
void checkBalance(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            char temp = pop();
            if ((ch == ')' && temp != '(') ||
                (ch == '}' && temp != '{') ||
                (ch == ']' && temp != '[')) {
                printf("Parentheses are NOT balanced\n");
                return;
            }
        }
    }
    if (top == -1)
        printf("Parentheses are balanced\n");
    else
        printf("Parentheses are NOT balanced\n");
}

int main() {
    char expr[100];
    printf("Enter expression: ");
    fgets(expr, 100, stdin);
    checkBalance(expr);
    return 0;
}

