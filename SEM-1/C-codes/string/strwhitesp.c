#include<stdio.h>
int main()
{
    char st3[100];
    int s=0;
    printf("Enter:-");
    gets(st3);
    puts(st3);
    for(int i=0;st3[i]!='\0';i++)
    {
        printf("%c\n",st3[i]);
        s=s+1;
    }
    printf("%s\n",st3);
    printf("length of char= %d\n",s);
    for(int i=s;i>=0;i--)
    {
        printf("%c",st3[i]);
    }
}