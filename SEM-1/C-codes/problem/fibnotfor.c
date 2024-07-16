#include<stdio.h>
int fib(int n);
void main()
{   int n,i;
    printf("Enter n th term:-");
    scanf("%d",&n);
    fib(n);
}
int fib(int n)
{   int i=0;
    if(i<n)
    {   if(i==0)
        {return 0;}
        else if(i==1)
        {return 1;}
        else
        {
            return fib(i)+fib(i+1);
        }
        i++;
        printf("%d\n",fib(i));
    }
}