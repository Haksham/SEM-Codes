#include<stdio.h>
int main()
{
    int n,i,j,l,a[100][100];
    printf("Enter number of rows:- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(l=(n-i);l>0;l--)
        {printf(" ");}
        for(j=1;j<=i;j++)
        {
            if(j>i/2)
            {printf("%d ",i-j+1);}
            else
            {printf("%d ",j);}
        }
        printf("\n");
    }
    for(i=n-1;i>0;i--)
    {
        for(l=(n-i);l>0;l--)
        {printf(" ");}
        for(j=1;j<=i;j++)
        {
            if(j>i/2)
            {printf("%d ",i-j+1);}
            else
            {printf("%d ",j);}
        }
        printf("\n");
    }
}