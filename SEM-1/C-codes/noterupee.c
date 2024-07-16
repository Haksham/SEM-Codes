#include<stdio.h>
int main()
{
    int n,i,j=1,r;
    printf("Enter your amount: ");
    scanf("%d",&n);
    printf("You need:\n");
    for(i=0;i<n;i++)
    {
        r=n%10;
        n=n/10;
        j=j*10;
        if(r%10==0)
        {
            printf("%d note of 10 rupee.\n",r);
        }
        else if(r%5==0)
        {
            printf("%d note of 5 rupee.\n",r);
        }
        else{
            printf("%d note of 2 rupee.\n",r);
        }
        
    }
}