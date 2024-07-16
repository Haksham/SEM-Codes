#include<stdio.h>
struct student
{
    char a[100];
    int age;
};
int main()
{
    struct student A = {"harsh",20};
    A.age=19;
    printf("%d ",A.age);
}