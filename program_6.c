//Name - Yashika Rathore Roll no.- CT-A-26
//decimal to binary conversion using stack
#include <stdio.h>
#define MAX 20
int main()
{
    int binary[MAX], top=-1;
    int decimal, num, remainder, i;
    pritnf("\nEnter the decimal number: ");
    scanf("%d",&decimal);
    num=decimal;
    if(num==0)
    {
        top++;
        binary[top]=0;
    }
    else
    {
        while(num>0)
        {
            remainder=num%2;
            top++;
            binary[top]=remainder;
            num=num/2;
        }
    }
    printf("\nBinary equivalent of %d is: ",decimal);
    while(top!=-1)
    {
        printf("%d",binary[top]);
        top--;
    }
    return 0;
}
