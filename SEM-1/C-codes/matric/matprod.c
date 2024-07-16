#include<stdio.h>
int main()
{
    int i,j,a[50][50],b[50][50],p[50][50],n1,n2,m1,m2,k;
    printf("For 1st matrix:\n");
    printf("Enter number of rows and col.:");
    scanf("%d%d",&n1,&m1);
    printf("Enter values:\n");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            printf("%d row %d col:",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("For 2nd matrix:\n");
    printf("Enter number of rows and col.:");
    scanf("%d%d",&n2,&m2);
    printf("Enter values:\n");
    for(i=0;i<n2;i++)
    {
        for(j=0;j<m2;j++)
        {
            printf("%d row %d col:",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }
    if(m1==n2)
    {
        printf("Product of matrix is:\n");
        for(i=0;i<n1;i++)
        {   for(j=0;j<m2;j++)
            {   for(k=0;k<n2;k++)
                { p[i][j]=p[i][j]+a[i][k]*b[k][j]; }
                printf("%d ",p[i][j]);
            }
            printf("\n");
        }

    }
}