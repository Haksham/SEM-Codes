#include<stdio.h>
#include<math.h>
int pal(int n);
void main()
{   int n,f;
    printf("Enter number:-");
    scanf("%d",&n);
    f=pal(n);
    if(f==n)
    {printf("Its palendrome");}
    else
    {printf("not");}
}
int pal(int n)
{   int i=1;
    if(n>10)
    {
        return pal(n/10)+(n%10)*10;
    }
    else
    {return n;}
}