//Name - Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#include <string.h>
#define MAX 20
int is_opernad(char c)
{
    if((c>='a' && c<='z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return 1;
    else
        return 0;
}
int is_operator(char c)
{
    if(c == '+'|| c=='-'|| c =='*'|| c=='/'|| c=='^')
        return 1;
    else
        return 0;
}
int priority(char c)
{
    if(c=="^")
        return 3;
    else if(c =='*' || c == '/')
        return 2;
    else if(c == '+'|| c=='-')
        return 1;
    else
        return 0;
}
int main()
{
    char infix[MAX],ch;
    char prefix[MAX][MAX], stack[MAX];
    int top_prefix = -1, top_stack = -1,i=0,j;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    while(infix[i]!='\0')
    {
        ch = infix[i];
        if(is_opernad(ch))
        {
            top_prefix++;
            prefix[top_prefix][0]=ch;
            prefix[top_prefix][1]='\0';
        }
        else if(ch=='(')
        {
            top_stack++;
            stack[top_stack]=ch;
        }
        else if(ch==')')
        {
            while(top_stack!=-1 && stack[top_stack]!='(')
            {
                char op=stack[top_stack--];
                char opd2[MAX],opd1[MAX],temp[MAX];
                strcpy(opd2,prefix[top_prefix--]);
                strcpy(opd1,prefix[top_prefix--]);
                sprintf(temp,"%c%s%s",op,opd1,opd2);
                strcpy(prefix[++top_prefix],temp);
            }
            top_stack--;
        }
        else if(is_operator(ch))
        {
            while(top_stack!=-1 && stack[top_stack]!='(' && priority(stack[top_stack])>=priority(ch))
            {
                char op=stack[top_stack--];
                char opd2[MAX],opd1[MAX],temp[MAX];
                strcpy(opd2,prefix[top_prefix--]);
                strcpy(opd1,prefix[top_prefix--]);
                sprintf(temp,"%c%s%s",op,opd1,opd2);
                strcpy(prefix[++top_prefix],temp);
            }
            stack[++top_stack]=ch;
        }
        i++;
    }
    while(top_stack!=-1)
    {
        char op=stack[top_stack--];
        char opd2[MAX],opd1[MAX],temp[MAX];
        strcpy(opd2,prefix[top_prefix--]);
        strcpy(opd1,prefix[top_prefix--]);
        sprintf(temp,"%c%s%s",op,opd1,opd2);
        strcpy(prefix[++top_prefix],temp);
    }
    printf("Prefix expression: %s\n",prefix[top_prefix]);
    return 0;
}
