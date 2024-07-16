#include<stdio.h>
void fun();
void fun()
{   int i,n;
    printf("Enter num:-");
    scanf("%d",&n);
    for(i=2;i<=n/2+2;i++)
    {
        if(n%i!=0)
        {printf("prime.");
        break;}
        else
        {printf("not prime");
        break;}
    }
}
void main()
{
    fun();
}