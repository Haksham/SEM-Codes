#include<stdio.h>
int *add(int *x,int *y);
int main()
{
    int a,b;
    printf("Enter 2 nos:\n");
    scanf("%d%d",&a,&b);
    printf("Sum= %d",*add(&a,&b));
}
int *add(int *x,int *y)
{
    *x=*x+*y;
    return x;
}