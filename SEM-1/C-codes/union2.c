#include<stdio.h>
union test
{
    int x;
    char y;
};
int main()
{
    union test p1;
    p1.x=6;
    union test *p2=&p1;
    printf("%d,%c",p2->x,p2->y);
}