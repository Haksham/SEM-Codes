#include"stdio.h"
int main()
{
    int m;
    printf("Enter yours marks to get your grade: ");
    scanf("%d",&m);
    if((m>=90)&&(m<=100))
    {
        printf("You have an 'S' grade.");
    }
    else if((m>=75)&&(m<90))
    {
        printf("You have an 'A' grade.");
    }
    else if((m>=60)&&(m<75))
    {
        printf("You have an 'B' grade.");
    }
    else if((m>=50)&&(m<60))
    {
        printf("You have an 'C' grade.");
    }
    else if((m>=40)&&(m<50))
    {
        printf("You have an 'D' grade.");
    }
    else if((m>0)&&(m<40))
    {
        printf("You have an 'F' grade.");
    }
    else{
        printf("Enter valid scores!!!");
    }
    return 0;
}