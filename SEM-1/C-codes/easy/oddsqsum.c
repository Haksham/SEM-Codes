#include<stdio.h>
int main()
{
    int n,s=0,i;
    printf("number of terms:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        s=s+(i*2+1)*(i*2+1);
    }
    printf("Sum of sq of odd=%d",s);
}