#include<stdio.h>
int main()
{
    int i,s=0,n,j,f=1,p=0;
    printf("number of terms:");
    scanf("%d",&n);
    for(i=0;i<=n/2;i++)
    {
        s=s+2*i;
    }
    for(i=1;i<=(n+1)/2;i++)
    {
        for(j=1;j<=(i*2-1);j++)
        {
            f=f*j;
        }
        p=f+p;
        f=1;
    }
    printf("sum=%d",p+s);
}