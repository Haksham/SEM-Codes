#include<stdio.h>
void main()
{
    int a;
    printf("Enter the year:");
    scanf("%d",&a);
    if ((a%4==0 && a%100!=0) || (a%400==0))
    {
        printf("Its a leap year");
    }
    else {
        printf("not a leap year");
    }
}