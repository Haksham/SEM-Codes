#include<stdio.h>
int main()
{
    char a[100];
    int i,j;
    printf("Enter:-");
    gets(a);
    for(i=0;a[i]!='\0';i++);
    for(j=i;j>=0;j--)
    {printf("%c",a[j]);}
    
}