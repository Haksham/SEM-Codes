#include<stdio.h>
void main()
{
    int a,b,c,x;
    printf("Enter your 3 numbers:\n");
    scanf("%d%d%d",&a,&b,&c);
    x=a;
    if (b>=x)
    {
        x=b;
        if(c>=x)
        {
            printf("c is biggest");
        }
        else
        {
            printf("b is biggest");
        }
    }
    else
    {
        printf("a is biggest");
    }
}