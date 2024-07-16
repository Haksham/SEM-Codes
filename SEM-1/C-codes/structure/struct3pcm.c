#include<stdio.h>
typedef struct 
{
    int sub1,sub2,sub3;
    float per;
}student;
int main()
{
    student a,b,c;
    printf("Marks should be under 100:-\n");
    printf("Enter marks of 1st student in sub1 = ");
    scanf("%d",&a.sub1);
    printf("Enter marks of 1st student in sub2 = ");
    scanf("%d",&a.sub2);
    printf("Enter marks of 1st student in sub3 = ");
    scanf("%d",&a.sub3);
    printf("Enter marks of 2nd student in sub1 = ");
    scanf("%d",&b.sub1);
    printf("Enter marks of 2nd student in sub2 = ");
    scanf("%d",&b.sub2);
    printf("Enter marks of 2nd student in sub3 = ");
    scanf("%d",&b.sub3);
    printf("Enter marks of 3nd student in sub1 = ");
    scanf("%d",&c.sub1);
    printf("Enter marks of 3nd student in sub2 = ");
    scanf("%d",&c.sub2);
    printf("Enter marks of 3nd student in sub3 = ");
    scanf("%d",&c.sub3);
    a.per=(a.sub1+a.sub2+a.sub3)/3;
    b.per=(b.sub1+b.sub2+b.sub3)/3;
    c.per=(c.sub1+c.sub2+c.sub3)/3;
    printf("avg of student 1 = %.2f\n",a.per);
    printf("avg of student 2 = %.2f\n",b.per);
    printf("avg of student 3 = %.2f\n",c.per);
    printf("avg of sub1 = %.2f\n",(a.sub1+b.sub1+c.sub1)/3);
    printf("avg of sub2 = %.2f\n",(a.sub2+b.sub2+c.sub2)/3);
    printf("avg of sub3 = %.2f\n",(a.sub3+b.sub3+c.sub3)/3);
}