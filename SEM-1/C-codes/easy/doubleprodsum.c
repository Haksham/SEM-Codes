#include<stdio.h>
int main()
{
    int n,s=0,i;
    printf("Enter number:");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        s=s+i*(i+1);
    }
    printf("Sum=%d",s);
}