//Name-Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#define MAX 20
int isopd(char c)
{
    if((c>='a' && c<='z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return 1;
    else
        return 0;
}
int isopr(char c)
{
    if(c == '+'|| c=='-'|| c =='*'|| c=='/'|| c=='^')
        return 1;
    else
        return 0;
}
int priority(char ch)
{
    if(ch == '^')
        return 3;
    if(ch =='*' || ch == '/')
        return 2;
    else
        return 1;
}
int main()
{
char infix[MAX], stk[MAX], opd[MAX];
int i=0, j=0, top=-1;
char ch;
printf("\nEnter the infix expression: ");
scanf("%s",infix);
while(infix[i]!='\0')
{
    ch = infix[i];
    if(ch == '(')
    {
        top++;
        stk[top]=ch;
    }
    else if(isopd(ch))
    {
        opd[j] = ch;
        j++;

    }
    else if(isopr(ch))
    {
        if(stk[top] =='(' || priority(ch)>priority(stk[top]))
        {
            top++;
            stk[top]= ch;
        }
        else
        {
            while(isopr(stk[top])&& priority(stk[top])>=priority(ch))
            {
                opd[j] = stk[top];
                top--;
                j++;
            }
            top++;
            stk[top] = ch;
        }

    }
    else
    {
        while(stk[top]!= '(')
        {
            opd[j] = stk[top];
            j++;
            top--;
        }
            top--;
    }
i++;
}
while(top != -1)
{
    opd[j++] = stk[top--];
}
opd[j] = '\0';
printf("\n\t\t Postfix expression is %s", opd);
return 0;
}