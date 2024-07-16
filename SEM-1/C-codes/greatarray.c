#include"stdio.h"
int main()
{
    int num[50],i;
    int readnum, numprint;
    printf("You can enter upto 50 no.\n");
    printf("How many would u like to enter: ");
    scanf("%d",&readnum);
    if (readnum<=50)
    {
        printf("Enter numbers:\n");
    }
    else if(readnum>50)
    {
        readnum=50;
        printf("Enter numbers:\n");
    }
    for(i=0;i<=readnum;i++){
    scanf("%d",&num[i]);}
    for (i=readnum,numprint=0;i>=0;i--)
        {
        printf("%d,",num[i]);
        if(numprint<4)
        {
            numprint++;
        }
        else
        {
            printf("\n");
            numprint=0;
        }
    }
    return 0;
}