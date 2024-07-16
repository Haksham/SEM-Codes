#include<stdio.h>
void main()
{
    float a,b;
    char o;
    printf("enter operator(+,-,/,*)= ");
    scanf("%c",&o);
    printf("enter nos: ");
    scanf("%f%f",&a,&b);
    switch (o)
    {
    case '+':
        printf("%.1f+%.1f=%.1f",a,b,a+b);
        break;
    case '-':
        printf("%.1f-%.1f=%.1f",a,b,a-b);
        break;
    case '*':
        printf("%.1f*%.1f=%.1f",a,b,a*b);
        break;
    case '/':
        printf("%.1f/%.1f=%.1f",a,b,a/b);
        break;
    default:
        printf("Invalid");
    }
}