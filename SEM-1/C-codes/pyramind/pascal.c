#include<stdio.h>
int main()
{
    int n,i,j,l,a[100][100],k;
    printf("Enter number of rows:- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(l=(n-i);l>0;l--)
        {printf(" ");}
        for(j=1;j<=i;j++)
        {
            if(j>i/2)
            {k=(i-j+1); }
            else
            {k=j;}
            a[i][j]=k;
            k=0;
        }
    }
    for(i=1;i<=n;i++)
    {   for(j=1;j<=i;j++)
        {
            if(j>0)
            {a[i+1][j+1]=a[i][j]+a[i][j+1];}
        }
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(l=(n-i);l>0;l--)
        {printf(" ");}
        for(j=1;j<=i;j++)
        {printf("%d ",a[i][j]);}
        printf("\n");
    }
}