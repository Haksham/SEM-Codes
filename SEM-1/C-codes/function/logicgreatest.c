#include <stdio.h>
int main()
{
    int a,b,c,d,e;
    printf("Enter 3 nos:- ");
    scanf("%d%d%d",&a,&b,&c);
    d=a>b?a:b;
    e=c>d?c:d;
    printf("%d is greatest",e);
}