#include<stdio.h>
typedef struct 
{
    int num;
    int dec;
}frac;
int main()
{   int i,temp;
    frac a,b,c;
    printf("1st fraction=");
    scanf("%d",&a.num);
    scanf("%d",&a.dec);
    printf("2nd fraction=");
    scanf("%d",&b.num);
    scanf("%d",&b.dec);
    c.num=a.num*b.num;
    c.dec=a.dec*b.dec;
    printf("%d/%d*%d/%d=%d/%d",a.num,a.dec,b.num,b.dec,c.num,c.dec);
}