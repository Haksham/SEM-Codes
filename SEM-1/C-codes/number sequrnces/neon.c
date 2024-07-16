#include<stdio.h>
int main()
{
    int n,s,p=0,r,i,k;
    printf("Enter number:- ");
    scanf("%d",&n);
    s=n*n;
    k=n;
    for(i=0;s!=0;i++)
    {
        r=s%10;
        p=p+r;
        s=s/10;
    }
    printf("%d,%d\n",p,s);
    if(p==k)
    {printf("yes neon.");}
    else
    {printf("no");}
}