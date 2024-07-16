#include<stdio.h>
enum op{add=1,sub,mul,div};
enum op o;
int main()
{
    int c,a,b;
    printf("Enter operator:- ");
    scanf("%d",&c);
    o=c;
    printf("Enter 2 nos:- ");
    scanf("%d%d",&a,&b);
    switch(o)
    {   
    case add:
        printf("%d+%d=%d",a,b,a+b);
        break;
    case sub:
        printf("%d-%d=%d",a,b,a-b);
        break;
    case mul:
        printf("%d*%d=%d",a,b,a*b);
        break;
    case div:
        printf("%d/%d=%d",a,b,a/b);
        break;
    default:
        printf("invalid");
    }
}