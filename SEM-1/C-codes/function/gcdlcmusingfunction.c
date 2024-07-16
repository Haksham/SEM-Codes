#include <stdio.h>
void lcm_gcd(int ,int); 
 
void main()
{
    int no1,no2;
 
    printf("Enter two Numbers\n");
    scanf("%d %d",&no1,&no2);
    lcm_gcd(no1,no2);
}

void lcm_gcd(int n1,int n2)
{
    int gcd,lcm,remainder,numerator,denominator;
      //To find numerator and denominator
    numerator = (n1>n2)?n1:n2;
    denominator = (n1<n2)?n1:n2;
    remainder = numerator % denominator;
    while (remainder!=0)
    {
        numerator=denominator;
        denominator=remainder;
        remainder=numerator%denominator;
    }
    gcd = denominator;
    lcm = n1*n2/gcd;

    printf("GCD of %d and %d = %d\n",n1,n2,gcd);
    printf("LCM of %d and %d = %d\n",n1,n2,lcm);
}