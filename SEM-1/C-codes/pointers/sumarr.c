#include<stdio.h>
int main()
{
    int a[50],i,n,*p;
    float s=0;
    printf("Enter number of arrays:");
    scanf("%d",&n);
    printf("Enter arrays:\n");
    for(i=0;i<n;i++)
    {scanf("%d",&a[i]);}
    p=&a[0];
    for(i=0;i<n;i++,p++)
    {s=s+*p;}
    printf("Avg= %f",s/n);
}