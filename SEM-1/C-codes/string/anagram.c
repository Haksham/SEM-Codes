#include<stdio.h>
#include<ctype.h>
void arrg(char *a);
int main()
{
    int i,f=1;
    char a[100],b[100];
    printf("Enter string 1:- ");
    gets(a);
    printf("Enter 2nd string:- ");
    gets(b);
    arrg(a);
    arrg(b);
    for(i=0;a[i]!='\0';i++)
    {
        if(tolower(a[i])!=tolower(b[i]))
        {f=0;
        break;}
    }
    if(f==0)
    {printf("not anagram");}
    else
    {printf("Anagram");}
}
void arrg(char *a)
{
    int i,j,k;
    char temp;
    for(k=0;a[k]!='\0';k++);
    for(i=0;i<k;i++)
    {
        for(j=0;j<k-1;j++)
        {
            if(a[j]>=a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}