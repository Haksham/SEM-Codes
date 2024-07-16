#include<stdio.h>
#include<math.h>
int main()
{
    int n,r,i;
    printf("Enter your number:");
    scanf("%d",&n);
    printf("Right most number is:%d\n",n%10);
    for(i=0;i<n;i++)
    {
        r=n/10;
        if(r<10)
        {
            printf("left most number is: %d",r);
            break;
        }
        else
        { n=n/10;}
    }
}