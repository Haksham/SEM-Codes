#include<stdio.h>
int main()
{
    int pos,n,i,j,a[50],temp;
    printf("Enter number of arrays you want:");
    scanf("%d",&n);
    printf("Enter arrays:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<(n-1);i++)
    { pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[pos])
            {
                pos=j;
            }
        }
        temp=a[pos];
        a[pos]=a[i];
        a[i]=temp;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}