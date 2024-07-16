#include <stdio.h>
int main()
{   int c=0;
    x:printf("%d ",c);
    if(c<10)
    { c++;
    goto x;
    }
}