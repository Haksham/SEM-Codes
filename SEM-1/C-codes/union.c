#include<stdio.h>
union test
{
    int x,y;

    float z;
}a;
int main()
{
    a.x=3;
    printf("%d\n%d\n",a.x,a.y);
    a.y=4;
    printf("%d\n%d\n",a.x,a.y);
    a.z=8;
    printf("%.2f",a.z);
}
