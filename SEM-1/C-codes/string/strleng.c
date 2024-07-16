#include<stdio.h>
int main()
{
    char a[100],b[100],c[100];
    int i=0,j;
    printf("Enter 1st string:- ");
    gets(a);
    printf("Enter 2nd string:- ");
    gets(b);
    for(i=0;a[i]!='\0';i++);
    printf("length of string = %d\n",i);
    while(a[i]!='\0')
    {
        a[i]=c[i];
        i++;
    }
    c[i]='\0';
    printf("c= %s",c);
    puts(c);
    for(i=0;a[i]!='\0';i++)
    {
        for(j=0;b[j]!='\0';j++)
        {
            a[i+j]=b[j];
        }
        a[i+j]='\0';
    }
    puts(a);
}