#include"stdio.h"
#include<math.h>
int main()
{
    int temp,n,dec=0,base=1,r;
    printf("Enter your binary:");
    scanf("%d",&n);
    temp=n;
    while(n>0)
    {
        r=n%10;
        dec=dec+r*base;
        n=n/10;
        base=base*2;
    }
    printf("decimal=%d\n",dec);
    printf("binary=%d",temp);
    return 0;
}