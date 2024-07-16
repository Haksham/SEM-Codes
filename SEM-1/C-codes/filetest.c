#include<stdio.h>
void show(char *x,FILE *y,char b[]);
void add(FILE *y,char b[]);
void write(char *x,FILE *y,char b[]);
void rena(char *b);
int main()
{
    FILE *fp;
    char a[100],b[100];
    int k,n=2;
    printf("Enter file name:-");
    gets(b);
    fp=fopen(b,"w");
    printf("Enter initial data:- ");
    gets(a);
    fputs(a,fp);
    fclose(fp);
    
    while(n!=0)
    {   printf("Enter command:- ");
        scanf("%d",&k);
            if(k==2)
            {add(fp,b);}
            if(k==1)
            {show(a,fp,b);}
            if(k==3)
            {write(a,fp,b);}
            if(k==4)
            {break;}
            if(k==0)
            {printf("0->Help\n1->Show\n2->Add\n3->Overwrite\n4->Exit\n5->Rename file\n6->Show file name.\n");}
            if(k==5)
            {rena(b);}
            if(k==6)
            {printf("file name:- %s\n",b);}
    }
}
void show(char *x,FILE *y,char b[])
{   
    fopen(b,"r");
    while(fgets(x,100,y)!=NULL)
    {
        printf("%s\n",x);
    }
    fclose(y);
}
void add(FILE *y,char b[])
{   int i=0;
    char c[100];
    fopen(b,"a");
    printf("Enter text to add:- ");
    while(i<2)
    {gets(c);
    i++;}
    fputs(c,y);
    fclose(y);
}
void write(char *x,FILE *y,char b[])
{   int i=0;
    char c[100];
    fopen(b,"w");
    printf("Rewrite:- ");
    while(i<2)
    {gets(c);
    i++;}
    fputs(c,y);
    fclose(y);
}
void rena(char *b)
{   int i=0;
    printf("Enter new file name:- ");
    while(i<2)
    {gets(b);
    i++;}
}