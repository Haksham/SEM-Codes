#include<stdio.h>
int main()
{
    char a[100],temp;
    int i,j,k;
    printf("Enter string :- ");
    gets(a);
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
    puts(a);
}