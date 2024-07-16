#include<stdio.h>
int nat(int n);
void main()
{   int n;
    printf("Enter number:-");
    scanf("%d",&n);
    printf("Sum till n = %d",nat(n));
}
int nat(int n)
{
    if(n>0)
    {
        return n+nat(n-1);
    }
}