#include<stdio.h>
int mag(int n);
int main()
{   int n,x;
    printf("Enter number:- ");
    scanf("%d",&n);
    x=mag(n);
    if(x==1)
    {printf("magic occured");}
    else
    {printf("Sorry magic failed");}
}
int mag(int n)
{
    int i,s=0,r;
    for(i=0;i<10;i++)
    {
        r=n%10;
        s=s+r;
        n=n/10;
    }
    if(s>=10)
    {return mag(s);}
    else
    {return s;}
}