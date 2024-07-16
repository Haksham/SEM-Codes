#include<stdio.h>
int main()
{
    int n,s=0,r,p;
    printf("Enter your number:");
    scanf("%d",&n);
    p=n;
    for(int i=0;i<10;i++)
    {
        r=n%10;
        s=s+r;
        n=n/10;
    }
    if(p%s==0)
    {printf("YES Harshad");}
    else
    {printf("noo");}
}