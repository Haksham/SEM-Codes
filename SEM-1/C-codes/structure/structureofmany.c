#include<stdio.h>
struct stud 
{
    int sub[3];
    int roll;
    float per;
}s[3];
int main()
{
    int i,j,n;
    printf("Enter how many students u want:- \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter roll no of student %d = \n",i+1);
        scanf("%d",&s[i].roll);
        for(j=0;j<3;j++)
       {printf("Enter marks of %d th subject= ",j+1);
        scanf("%d",&s[i].sub[j]);}
    }
    
}