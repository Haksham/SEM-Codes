#include"stdio.h"
int main()
{
    int temp,sum=0,n,r;
    printf("Enter your number: ");
    scanf("%d",&n);
    temp=n;
    while(n>0)
    {
        r=n%10;
        sum=sum*10+r;
        n=n/10;
    }
    if(temp==sum)
    {
        printf("Entered num is palendrome");
    }
    else{
        printf("Not a palendrome.");
    }
}