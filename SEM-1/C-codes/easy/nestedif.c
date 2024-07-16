#include<stdio.h>
int main() 
{
    int a;
    printf("Enter your number: ");
    scanf("%d",&a);
    if(a%2==0)
    {
        printf("Number is even ");
        if(a%4==0)
        {
            printf("and div by 4.");
        }
        else
        {
            printf("not div by 4.");
        }
    }
    else
    {
        printf("Number is odd ");
        if(a%3==0)
        {
            printf("and div by 3.");
        }
        else
        {
            printf("not div by 3.");
        }
    }
  return 0;
}