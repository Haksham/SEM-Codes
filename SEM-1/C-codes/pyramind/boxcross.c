#include<stdio.h>
int main ()
{
    int i,j,k,l,n=6;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0||i==n||j==n||j==i||j==n-i)
            {printf("* ");}
            else
            {printf("  ");}
        }
        printf("\n");
    }
}