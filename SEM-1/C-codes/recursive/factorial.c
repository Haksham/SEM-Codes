#include<stdio.h>
int fact(int n);
void main()
{
    int n;
    printf("Enter number:-");
    scanf("%d",&n);
    printf("factorial of %d = %d",n,fact(n));
}
int fact(int n)
{
    if(n!=0)
    {
        return n*fact(n-1);
    }
    else if(n==0)
    {
        return 1;
    }
}   