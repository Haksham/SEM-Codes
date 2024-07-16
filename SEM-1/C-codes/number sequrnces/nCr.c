#include<stdio.h>
int fact(int x);
int main()
{
    int n,r;
    printf("Enter n= ");
    scanf("%d",&n);
    printf("Enter r= ");
    scanf("%d",&r);
    printf("Vale of nCr= %d",(fact(n)/(fact(r)*fact(n-r))));
}
int fact(int x)
{
    if(x>0)
    {return x*fact(x-1);}
    else
    {return 1;}
}