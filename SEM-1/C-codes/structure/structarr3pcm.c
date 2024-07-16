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
    float stdavg[3];
    printf("Enter how many students u want:- \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter roll no of student %d = \n",i+1);
        scanf("%d",&s[i].roll);
        for(j=0;j<3;j++)
       {printf("Enter marks of %d th subject= ",j+1);
        scanf("%d",&s[i].sub[j]);
        stdavg[i]=stdavg[i]+s[i].sub[j];}
        printf("\n");
    }
    printf("Data:-\n");
    for(i=0;i<n;i++)
    {
        printf("Roll no. %d\n",s[i].roll);
        for(j=0;j<n;j++)
        {
            printf("marks of %d subject = %d\n",j+1,s[i].sub[j]);
        }
        printf("avg= %.2f\n\n",(stdavg[i])/3);

    }
}