#include<stdio.h>
int main()
{
    int i,sz;
    int sum=0;
    printf("Enter array size: ");
    scanf("%d",&sz);
     int a[sz];
    for(i=0;i<sz;i++)
    {
        a[i]=i*i;
    }
    printf("Arrays are: \n");
    for(i=0;i<sz;i++)
    {
        printf("%d\n",a[i]);
    }
    for(i=0;i<sz;i++)
    {
        sum=sum+a[i];
    }
    printf("Sum of square of array is: %d\n",sum);
    printf("Reversed order is:\n");
    for(i=sz-1;i>=0;i--)
    {
        printf("%d\n",a[i]);
    }
    printf("Sum of second and last array is: %d",(a[1]+a[sz-1]));
    return 0;
}