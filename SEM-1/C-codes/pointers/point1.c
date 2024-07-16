#include<stdio.h>
int main()
{
    int a=10,*p;
    p=&a;
    printf("%d\n",*p);
    printf("%d\n",a);
    printf("%d\n",p);
    a++;
    ++*p;
    printf("%d\n",*p);
    printf("%d\n",a);
}