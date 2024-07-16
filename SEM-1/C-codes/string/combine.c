#include<stdio.h>
void comb(char a[],char b[]);
int main() 
{
    char a[100],b[100];
    int i;
    printf("Enter string 1:- ");
    gets(a);
    printf("Enter 2nd string:- ");
    gets(b);
    comb(a,b);
}
void comb(char a[],char b[])
{   int i,j;
    for(i=0;a[i]!=0;i++);
    for(j=0;b[j]!='\0';j++)
    {a[i+j]=b[j];}
    a[i+j]='\0';
    printf("%s",a);
}