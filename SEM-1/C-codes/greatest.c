#include<stdio.h>
void main()
{
    int a,b,c;
    printf("enter :\n");
    scanf("%d%d%d",&a,&b,&c);
    if ((a>b) && (a>c))
        {printf("a is greatest");}
    else if ((c>b) && (c>a))
    {
        printf("c is greatest");
    }
    else {
        printf("b is greatest");
    }
}