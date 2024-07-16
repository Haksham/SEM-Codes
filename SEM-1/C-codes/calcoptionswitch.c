#include<stdio.h>
int main()
{
    float a,b;
    char o;
    printf("1= +\n2= -\n3= *\n4= /\n");
    printf("enter operator=  ");
    scanf("%c",&o);
    printf("enter nos: ");
    scanf("%f%f",&a,&b);
    switch (o)
    {
    case '1':
        printf("%.1f+%.1f=%.1f",a,b,a+b);
        break;
    case '2':
        printf("%.1f-%.1f=%.1f",a,b,a-b);
        break;
    case '3':
        printf("%.1f*%.1f=%.1f",a,b,a*b);
        break;
    case '4':
        printf("%.1f/%.1f=%.1f",a,b,a/b);
        break;
    default:
        printf("Invalid");
    }
}