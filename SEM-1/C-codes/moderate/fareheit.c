#include<stdio.h>
void main()
{
    float c,f,v;
    char u;
    printf("Enter unit: ");
    scanf("%c",&u);
    printf("Enter value :");
    scanf("%f",&c);
    if(u=='c')
       { f=(c*1.8)-32;
        printf("the value in fahrenheit is: %fF",f);
       }
    else if(u=='f')
       { 
        v=(c+32)/1.8;
        printf("The value in celsius is: %fC",v);
       }
    else
      {  printf("Invalid");
      }
}