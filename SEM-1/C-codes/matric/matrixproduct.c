#include<stdio.h>
int main()
{
    int i,j,n1,m1,a[50][50],n2,m2,b[50][50],s[50][50],p=0,k;
    s[0][0]=0;
    printf("For 1st matrix(A)\n");
    printf("Enter number of rows: \n");
    scanf("%d",&n1);
    printf("Enter number of columns: \n");
    scanf("%d",&m1);
    printf("Enter numbers:\n");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            printf("for %d row %d column:",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n");
    printf("For 2nd matrix(B)\n");
    printf("Enter number of rows: \n");
    scanf("%d",&n2);
    printf("Enter number of columns: \n");
    scanf("%d",&m2);
    printf("Enter numbers:\n");
    for(i=0;i<n2;i++)
    {
        for(j=0;j<m2;j++)
        {
            printf("for %d row %d column:",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }
    if(m1==n2)
    {
        printf("product of matrix is:\n");
        for(i=0;i<n1;i++)
        {
            for(j=0;j<m2;j++)
            {
                for(k=0;k<m1;k++)
                {
                    p=a[i][k]*b[k][i]+p;
                }
            s[i][j]=p;
            p=0;
            }
        }
        for(i=0;i<n1;i++)
        {   for(j=0;j<m2;j++)
            {printf("%d ",s[i][j]);}
            printf("\n");}
    }
    else{
        printf("Matrix multiplication not possible.");
    }
}