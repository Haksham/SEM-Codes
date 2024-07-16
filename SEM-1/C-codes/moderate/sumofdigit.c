#include<stdio.h>
int main()
{
    int n,r,s=0;
    printf("Enter your number: ");
    scanf("%d",&n);
    while(n!=0)
    {
        r=n%10;
        n=n/10;
        s=r+s;
    }
    printf("sum is %d",s);
}