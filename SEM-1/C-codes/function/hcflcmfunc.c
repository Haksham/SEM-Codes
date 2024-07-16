#include<stdio.h>
void fun(int a,int b);
int main()
{
    int a,b;
    printf("Enter 2 nos:-\n");
    scanf("%d%d",&a,&b);
    fun(a,b);
}
void fun(int a, int b)
{
    int i,lcm,hcf;
    for(i=1;i<=a*b;i++)
        {
            if(a%i==0 && b%i==0)
            {hcf=i;}
            
        }
    lcm=a*b/hcf;
    printf("lcm=%d\n",lcm);
    printf("Hcf=%d",hcf);
}
