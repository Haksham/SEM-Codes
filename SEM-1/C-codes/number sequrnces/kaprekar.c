#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,p,s=0,k,r,l,q,ans,z;
    float a;
    printf("Enter number:- ");
    scanf("%d",&n);
    p=n*n;
    q=n*n;
    printf("p= %d, q= %d\n",p,q);
    for(i=0;i<50;i++)
    {
        if(p!=0)
        {s=s+1;
        p=p/10;}
        else
        {break;}
    }
    z=s/2;
    if(s%2!=0)
    {z=z+1;}
    printf("z= %d\n",z);
    printf("s= %d\n",s);
    a=pow(10,(z));
    printf("a= %.0f\n",a);
    l=q/a;
    r=q-l*a;
    printf("%d,%d\n",r,l);
    ans=r+l;
    if(ans==n)
    {printf("yay");}
    else
    {printf("noo");}
}