#include<stdio.h>
int main()
{
    int a,b;
    printf("enter your first number:");
    scanf("%d",&a);
    printf("enter your second number:");
    scanf("%d",&b);
    if (a>b) {   
        printf(" first is greater.");
    }
    else if (b>a)
     {
        printf("second is greater.");
    }
    else {
        printf("both are equal");
    }
}