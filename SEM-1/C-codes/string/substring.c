#include <stdio.h>
int main()
{
    char a[80],b[80];
    int l,i,j;
    printf("Enter main string: ");
    gets(a);
    printf("Enter sub-string: ");
    gets(b);
    for(l=0;b[l]!='\0';l++);
    for(i=0,j=0;a[i]!='\0'&&b[j]!='\0';i++)
    {   if(a[i]==b[j])
        {j++;}
        else
        {j=0;}
    }
    if(j==l)
    {printf("Substring found at position %d",i-j+1);}
    else
    {printf("Substring not found");}
}