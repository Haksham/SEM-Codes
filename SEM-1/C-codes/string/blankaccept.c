#include<stdio.h>
int main()
{
    char a[100];
    int s=0,i;
    printf("Enter:-");
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {s=s+1;}
    printf("length of char= %d\n",s);
    for(i=s;i>=0;i--)
    {printf("%c",a[i]);}
    printf("\n");
    for(i=0;a[i]!=' ';i++)
    {
        printf("%c",a[i]);
    }
}