#include<stdio.h>
int *gre(int *x,int *y);
int main()
{
    int a,b,*max;
    printf("Enter 2 values:\n");
    scanf("%d%d",&a,&b);
    max=gre(&a,&b);
    printf("%d is greatest",*max);
}
int *gre(int*x,int *y)
{
    if(*x>*y)
    {return x;}
    else
    {return y;}
}