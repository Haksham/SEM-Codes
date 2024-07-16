#include<stdio.h>
int main()
{
    int n,i,j,k,l;
    printf("Enter number of rows:- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {   
        for(l=(n-i);l>0;l--)
        {printf("  ");}
        for(j=1;j<=i;j++)
        {printf("%d ",j);}
        for(k=i-1;k>0;k--)
        {printf("%d ",k);}
        printf("\n");
    }
    for(i=n-1;i>0;i--)
    {   
        for(l=(n-i);l>0;l--)
        {printf("  ");}
        for(j=1;j<=i;j++)
        {printf("%d ",j);}
        for(k=i-1;k>0;k--)
        {printf("%d ",k);}
        printf("\n");
    }
}