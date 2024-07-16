#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    int c=0;
    gets(a);
    gets(b);
    for(int i=0;a[i]!='\0'&&b[i]!='\0';i++)
    {
        if(a[i]==b[i])
        {continue;}
        else
        {c=a[i]>b[i]?1:-1;
        break;}
    }
    printf("%d",c);
}