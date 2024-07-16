#include<stdio.h>
int main()
{
    char *p,a[40];
    printf("Enter string:- ");
    gets(a);
    p=&a[0];
    printf("%d\n",p);
    printf("%c\n",*p);
    printf("%s",a);
}