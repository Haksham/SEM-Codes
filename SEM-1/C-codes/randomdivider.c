#include<stdio.h>
#include<ctype.h>
int main()
{
    int i,j=0,k=0,l=0;
    char a[100000],b[10000],c[10000],d[10000];
    printf("Enter randon text:- ");
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(isupper(a[i]))
        {b[j]=a[i];
        j++;}
        else if(isdigit(a[i]))
        {c[k]=a[i];
        k++;}
        else if(islower(a[i]))
        {d[l]=a[i];
        l++;}
    }
    b[j]='\0';
    c[k]='\0';
    d[l]='\0';
    printf("\n\n");
    for(i=0;b[i]!='\0';i++)
    {printf("%c",b[i]);}
    printf("\n");
    for(i=0;c[i]!='\0';i++)
    {printf("%c",c[i]);}
    printf("\n");
    for(i=0;d[i]!='\0';i++)
    {printf("%c",d[i]);}
}