//Name - Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int numStack[MAX];
char opStack[MAX];
int topNum = -1, topOp = -1;
void pushNum(int x) 
{
    numStack[++topNum] = x;
}
int popNum() 
{
    return numStack[topNum--];
}
void pushOp(char c) 
{
    opStack[++topOp] = c;
}
char popOp() 
{
    return opStack[topOp--];
}
int priority(char c) 
{
    if(c == '^') 
        return 3;
    else if(c == '*' || c == '/') 
        return 2;
    else if(c == '+' || c == '-') 
        return 1;
    return 0;
}
int calc(int a, int b, char op) {
    if (op == '+') 
        return a + b;
    if (op == '-') 
        return a - b;
    if (op == '*') 
        return a * b;
    if (op == '/') 
        return a / b;
    return 0;
}
int main() 
{
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);
    int i = 0;
    while (exp[i] != '\0') 
    {
        if (exp[i] == ' ') {
            i++;
            continue;
        }
        if (isdigit(exp[i])) 
        {
            int value = 0;
            while (isdigit(exp[i])) {
                value = value * 10 + (exp[i] - '0');
                i++;
            }
            pushNum(value);
            continue;
        }
        if (exp[i] == '(') {
            pushOp(exp[i]);
            i++;
            continue;
        }
        if (exp[i] == ')') {
            while (topOp != -1 && opStack[topOp] != '(') {
                int b = popNum();
                int a = popNum();
                char op = popOp();
                pushNum(calc(a, b, op));
            }
            popOp(); 
            i++;
            continue;
        }
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') 
        {
            while (topOp != -1 &&
                   priority(opStack[topOp]) >= priority(exp[i])) 
            {
                int b = popNum();
                int a = popNum();
                char op = popOp();
                pushNum(calc(a, b, op));
            }
            pushOp(exp[i]);
            i++;
            continue;
        }
    }
    while (topOp != -1) {
        int b = popNum();
        int a = popNum();
        char op = popOp();
        pushNum(calc(a, b, op));
    }
    printf("RESULT = %d\n", popNum());
    return 0;
}

