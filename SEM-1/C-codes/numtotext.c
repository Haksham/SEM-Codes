#include<stdio.h>
void text(int a);
int main()
{
    int n,i,r,k=0,m;
    printf("Enter number:- ");
    scanf("%d",&n);
    while(n!=0)
    {
        m=n%10;
        k=k*10+m;
        n=n/10;
    }
    for(i=0;i<10;i++)
    {   if(k!=0)
        {r=k%10;
        k=k/10;
        text(r);}
    }
}
void text(int a)
{
    if(a==1)
    {printf("one ");}
    if(a==2)
    {printf("two ");}
    if(a==3)
    {printf("three ");}
    if(a==4)
    {printf("four ");}
    if(a==5)
    {printf("five ");}
    if(a==6)
    {printf("six ");}
    if(a==7)
    {printf("seven ");}
    if(a==8)
    {printf("eight ");}
    if(a==9)
    {printf("nine ");}
    if(a==0)
    {printf("zero ");}
}