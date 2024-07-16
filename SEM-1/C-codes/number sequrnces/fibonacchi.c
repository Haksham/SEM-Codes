#include"stdio.h"
int main()
{
    int num,i;
    printf("Enter how many terms you want to get: ");
    scanf("%d",&num);
    int n1=0;
    int n2=1;
    int n3;
    printf("%d\n%d\n",n1,n2);
    for(i=2;i<num;i++)
    {
        n3=n1+n2;
        printf("%d\n",n3);
        n1=n2;
        n2=n3;
    }
}