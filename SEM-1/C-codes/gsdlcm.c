#include<stdio.h>
int main()
{   int a,b,i,hcf,lcm;
    printf("Enter 2 nos:-\n");
    scanf("%d%d",&a,&b);
        for(i=1;i<=a*b;i++)
        {
            if(a%i==0 && b%i==0)
            {hcf=i;}
        }
    lcm=a*b/hcf;
    printf("lcm=%d\n",lcm);
    printf("Hcf=%d",hcf);
}