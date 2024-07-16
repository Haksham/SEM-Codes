#include<stdio.h>
int main()
{
    int n,i,j,l;
    printf("Enter number of rows:- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(l=(n-i);l>0;l--)
        {printf(" ");}
        for(j=1;j<=i;j++)
        {   
            printf("**");}
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {printf(" ");}
        printf("|\n");
    }
    for(i=n;i>0;i--)
    {
        for(l=(n-i);l>0;l--)
        {printf(" ");}
        for(j=1;j<=i;j++)
        {   
            printf(" *");}
        printf("\n");
    }
}