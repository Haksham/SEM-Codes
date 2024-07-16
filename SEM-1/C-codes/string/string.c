#include<stdio.h>
int main()
{
    char st1[]="hello";
    char st2[]={'h','e','l','l','\0'};
    printf("%s+%s\n",st1,st2);
    printf("%s\n",st1);
    char st3[100];
    int s=0;
    printf("Enter:-");
    scanf("%s",st3);
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
    printf("\n");
    printf("%s+%s=%s%s",st1,st2,st1,st2);
}