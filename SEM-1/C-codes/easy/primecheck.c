#include"stdio.h"
int main()
{
    int n,f=0,i;
    printf("Enter number:");
    scanf("%d",&n);
    for(i=2;i<=(n/2)+1;i++)
    {
        if(n%i==0)
        {printf("not prime.");
        break;}
        else
        {printf("Its prime");
        break;}
    }
}