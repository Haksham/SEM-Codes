#include<stdio.h>
#include<ctype.h>
int main()
{
    char in;
    printf("Enter your character:");
    scanf("%c",&in);
    if(islower(in))
    {
        printf("Its in lower case.");
    }
    else if(isupper(in))
    {
        printf("Its upper case.");
    }
    else if(isdigit(in))
    {
        printf("Its a digit.");
    }
    else if(ispunct(in))
    {
        printf("Its punctuation.");
    }
    else if(isspace(in))
    {
        printf("Whitespace.");
    }
    else{
        printf("Control character.");
    }
}