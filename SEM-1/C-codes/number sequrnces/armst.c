#include<stdio.h>
int main()
{
    int n,sum=0,m;
    printf("Enter your number:");
    scanf("%d",&n);
    int temp=n;
    while(n>0)
    { 
    m=n%10;
    sum=sum+(m*m*m);
    n=n/10;
    }
    if(temp==sum)
    {
        printf("yes its armstrong");
    }
    else
    {
        printf("not an armstrong number");
    }
}