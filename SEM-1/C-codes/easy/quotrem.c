#include<stdio.h>
int main()
{
    int a,b,q,r;
    printf("Enter your numbers:\n");
    scanf("%d%d",&a,&b);
    q=a/b;
    r=a%b;
    printf("Quotient is:%d\n",q);
    printf("Remainder is:%d",r);
    return 0;
}