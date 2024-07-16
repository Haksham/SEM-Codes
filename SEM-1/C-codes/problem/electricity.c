#include<stdio.h>
int main()
{
    float uc,t,a,x[50];
    printf("Enter the name of user:\n");
    scanf("%s",&x[50]);
    printf("Enter number of units consumed:\n");
    scanf("%f",&uc);
    if(uc<=200)
    {
        t=100+(0.8*uc);
    }
    else if((uc>200)&&(uc<=300))
    {
        t=100+160+(0.9*(uc-200));
    }
    else if(uc>300)
    {   
        a=100+160+90+(uc-300)*1;
        if(a>400)
        {  
            t=a+(0.15*a);
        }
        else if (a<=400)
        {
            t=a;
        } 
    }
    printf("Dear your total amount is %.2f",t);
    return 0;
}