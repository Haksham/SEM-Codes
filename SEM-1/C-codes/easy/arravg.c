#include <stdio.h>
int main()
{
    int a[50],i;
    float s=0,n;
    printf("Enter number of arrays:");
    scanf("%f",&n);
    printf("Enter arrays:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s=s+a[i];
    }
    printf("%f",s/n);

}