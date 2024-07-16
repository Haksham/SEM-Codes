#include<stdio.h>
int main()
{
    int n,i=0;
    int arr[50];
    printf("Enter number of arrays:");
    scanf("%d",&n);
    while(i<n)
    {
        printf("enter nos:\n");
        scanf("%d",&arr[i]);
        i++;
    }
    for(i=0;i<n;i++)
    {printf("%d,",arr[i]);}
    return 0;
}