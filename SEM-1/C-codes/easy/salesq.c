#include<stdio.h>
int main()
{
    float uc,dis,tax,a,tot;
    int q;
    printf("Enter unit price:- ");
    scanf("%f",&uc);
    printf("Enter quatity sold :- ");
    scanf("%d",&q);
    printf("Enter discount :- ");
    scanf("%f",&dis);
    printf("Enter tax rate:- ");
    scanf("%f",&tax);
    a=q*uc-q*uc*dis/100;
    tot=a+a*(tax/100);
    printf("Total sales= %.2f",tot);
}