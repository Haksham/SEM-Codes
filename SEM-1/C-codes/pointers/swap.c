#include<stdio.h>
void swap(int * x,int *y);
int main()
{
    int a,b;
    printf("Enter 2 values:\n");
    scanf("%d%d",&a,&b);
    printf("Before swap values= %d,%d\n",a,b);
    swap(&a,&b);
    printf("After swap values= %d,%d\n",a,b);
}
void swap(int *x, int* y)
{
    printf("address of a= %d\n",&x);
    printf("address of b= %d\n",&y);
    int temp=*x;
    *x=*y;
    *y=temp;
    printf("%d,%d\n",*x,*y);
    printf("address of b= %d\n",&x);
    printf("address of a= %d\n",&y);
}