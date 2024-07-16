#include<stdio.h>
void text(char x,int n);
int main()
{
    int n,i,j;
    char a[200];
    printf("Enter your text:- ");
    gets(a);
    printf("Enter width:- ");
    scanf("%d",n);
    for(i=0;i<n;i++)
    {
        text(a[i],n);
    }
}
void text(char x,int n)
{
    int i,j,k;
    if(x=='a')
    {printf("1");}
    else if(x=='b')
    {printf("2");}
}