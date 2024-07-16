#include<stdio.h>
int main()
{
    int n,i,s;
    int a[50];
    printf("Enter how many units u want to place: ");
    scanf("%d",&n);
    printf("Enter the arrays: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter item you want to search: ");
    scanf("%d",&s);
    for(i=0;i<n;i++)
    {
        if(s==a[i])
        {
            printf("Item %d is located at %d th position.\n",s,i+1);
            break;
        }
    }
    printf("after loop ,value of i=%d\n",i);
    if(i==n)
    {
        printf("Item not found.");
    }
    return 0;
}