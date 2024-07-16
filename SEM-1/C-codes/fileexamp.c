#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fp;
    char data[202];
    fp=fopen("lol.txt","w");
    if(fp==NULL)
    {printf("Empty");}
    else
    {   if(strlen(data)>0)
        {
        printf("Access granted\n");
        fputs("laude hu hii tuu",fp);
        fputs("\n",fp);
        }
        fclose(fp);
        printf("Write success\n");
    }
    fp=fopen("lol.txt","r");
    while(fgets(data,202,fp)!=NULL)
    {
        printf("%s",data);
    }
    fclose(fp);
    printf("File closed\n");
}