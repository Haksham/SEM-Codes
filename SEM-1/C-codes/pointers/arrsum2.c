#include<stdio.h>
int main()
{   int i,n,a[100],*p[100];
    float res=0;
    printf("Enter size of arrays:-");
    scanf("%d",&n);
    printf("Enter arrays:-\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        p[i]=&a[i];
        res=*p[i]+res;
    }
    printf("Sum of arrays= %.2f",res/n);
}