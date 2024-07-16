#include<stdio.h>
#include<math.h>
int main()
{
    float r1,r2,R,I,d,a,b,c;
    printf("Enter a,b,c:\n");
    scanf("%f%f%f",&a,&b,&c);
    d=(b*b)-(4*a*c);
    r1=(-b+sqrt(d))/(2*a);
    r2=(-b-sqrt(d))/(2*a);
    R=(-b/(2*a));
    I=sqrt(-d)/(2*a);
    if(d>0) {
        printf("Roots are real and different.\n>>(%.1f,%.1f)",r1,r2);
    }
    else if(d==0)
    {
        printf("Roots are equal and real.\n>>(%.1f,%.1f)",r1,r1);
    }
    else if(d<0)
    {
        printf("Roots are imagionary and different.\n>>(%.1f-i%.1f),(%.1f+i%.1f)",R,I,R,I);
    }
    else
    {
        printf("Invalid");
    }
    return 0;
}