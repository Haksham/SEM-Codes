#include<stdio.h>
int main()
{
    int n,i,j,f,s=0;
    printf("Enter n th value range:- ");
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {   f=0;
        for(j=2;j<i/2+1;j++)
        {
            if(i%j==0)
            {f=1;
            break;}
        }
        if(f==0)
        {printf("%d ",i);
        s=s+i;}
    }
    printf("\nSum of prime nos= %d",s);
}