#include<stdio.h>
#include<math.h>
int main()
{
    int n,s,i,r,k=0,a,o;
    printf("Enter number:- ");
    scanf("%d",&n);
    s=n*n;
    o=n;
    for(i=0;i<20;i++)
    {
        if(n!=0)
        {n=n/10;
        k=k+1;}
        else
        {break;}
    }
    a=pow(10,k);
    if((s-o)%a==0)
    {printf("yes");}
    else{printf("no");}
}