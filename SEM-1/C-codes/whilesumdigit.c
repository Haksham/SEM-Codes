#include<stdio.h>
int main()
{
    int n,i,r,s=0;
    printf("Enter your number: ");
    scanf("%d",&n);
    while(n>0)
    {
        r=n%10;
        s=r+s;
        n=n/10;
    }
    printf("sum is %d",s);
}