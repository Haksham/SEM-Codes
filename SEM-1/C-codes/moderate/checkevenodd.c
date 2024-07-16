#include<stdio.h>
void main()
{
    int a;
    printf("Enter your number:\n");
    scanf("%d",&a);
    if (a%2==0)
    {
        printf("Entered number is even");
    }
    else if (a%2!=0)
    {
        printf("Entered number is odd");
        }
}