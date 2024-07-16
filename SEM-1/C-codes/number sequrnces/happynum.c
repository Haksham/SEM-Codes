#include<stdio.h>
int hap(int n);
int main()
{
    int n,x;
    printf("Enter number:- ");
    scanf("%d",&n);
    x=hap(n);
    if(x==1)
    {printf("Happy");}
    else
    {printf("Saddd");}
}
int hap(int n)
{
    int i,s=0,r;
    for(i=0;i<10;i++)
    {r=n%10;
    s=s+r*r;
    n=n/10;}
    if(s>=10)
    {return hap(s);}
    else
    {return s;}
}