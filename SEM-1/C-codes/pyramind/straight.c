#include<stdio.h>
int main()
{
    int i,j,k,n,l,p,q;
    printf("Enter number of rows:- ");
    scanf("%d",&l);
    n=3*l;
    for(i=0;i<=n/3;i++)
    {
        for(k=n-i;k>0;k--)
        {printf(" ");}
        for(j=0;j<i;j++)
        {printf("* ");}
        printf("\n");
    }
    for(i=0;i<n/3;i++)
    {
        for(k=0;k<2*n/3;k++)
        {printf(" ");}
        for(j=0;j<n/3;j++)
        {printf("* ");}
        printf("\n");
    }
    for(i=0;i<n/3;i++)
    {
        for(k=n;k>n/3-i;k--)
        {printf(" ");}
        for(j=i;j<n/3;j++)
        {printf("* ");}
        printf("\n");
    }
}