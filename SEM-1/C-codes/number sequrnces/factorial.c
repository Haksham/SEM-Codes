#include<stdio.h>
int main()
{
    int n,f,i;
    f=1;
    printf("Enter the number: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    printf("factorial is: %d",f);
}