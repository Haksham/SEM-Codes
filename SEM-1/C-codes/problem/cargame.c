#include<stdio.h>
#include<string.h> 
int main()
{   int i=0;
    char s[20];
    printf("Welcome to my car game:\n");
    printf("Instruction are:\nhelp=get instructions.");
    while(i>0)
    {
        printf("Enter you order:");
        scanf("%s",s);
        if(s=='start')
        {
            printf("Car started moving.");
        }
        else if(s=='stop')
        {
            printf("Car stopped.");
        }
        else if(s=='help')
        {
            printf("\nstart=start the car.\nstop=stop the car.\nquit=quit the game.");
        }
        else
        {
            printf("I dont understand.");
        }
    }
}