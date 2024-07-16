#include<stdio.h>
int main()
{
    int k,j,i,n,l;
    printf("Enter number of rows:- ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(k=0;k<2*n;k++)
        {printf(" ");}
        for(j=0;j<n;j++)
        {printf("* ");}
        printf("\n");
    }
    for(i=0;i<=n;i++)
    {
        for(k=n;k>i;k--)
        {printf("  ");}
        for(j=i;j>0;j--)
        {printf("* ");}
        printf("\n");
    }
}