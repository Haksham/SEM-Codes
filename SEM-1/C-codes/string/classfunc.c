#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    printf("Enter 1st:- ");
    gets(a);
    printf("Enter 2nd:- ");
    gets(b);
    printf("%s\n",strcat(a,b));
    printf("%d\n",strlen(a));
    printf("%d\n",strlen(b));
}