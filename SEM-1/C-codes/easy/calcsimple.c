#include<stdio.h>
int main()
{
    int a,b,r;
    char d;
    printf("Enter operator: ");
    scanf("%c",&d);
    printf("Enter your numbers:\n");
    scanf("%d%d",&a,&b);
   
    if(d=='+')
    {
        r=a+b;
        printf("your ans is: %d",r);
    }
    else if(d=='-')
    {
        r=a-b;
        printf("your ans is: %d",r);
    }
    else if(d=='*')
    {
        r=a*b;
        printf("your ans is: %d",r);
    }
    else if(d=='/')
    {
        r=a/b;
        printf("ans is: %d",r);
    }
    else
    {
        printf("what are you doing!!!Incorrect");
    }
return 0;
}