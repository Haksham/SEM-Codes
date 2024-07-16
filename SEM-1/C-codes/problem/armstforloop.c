#include<stdio.h>
int main()
{
    int sum=0,m,i;
    for(i=1;i<=500;i++)
    {
    m=i%10;
    sum=sum+(m*m*m);
    i=i/10;
    printf("%d",sum);
    }
}