#include<stdio.h>
int comp(char a[],char b[]);
int main() 
{
    char a[100],b[100];
    int i,f;
    printf("Enter string 1:- ");
    gets(a);
    printf("Enter 2nd string:- ");
    gets(b);
    f=comp(a,b);
    if(f==0)
    {printf("same");}
    else
    {printf("Not.");}
}
int comp(char a[],char b[])
{
    int i,f=0;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!=b[i])
        {f=1;
        break;}
    }
    if(f==0)
        return 0;
    else
        return 1;
}