#include<stdio.h>
int main()
{
    int i,j,n1,m1,a[50][50],n2,m2,b[50][50],s[50][50],s1=0,s2=0,temp;
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
            s1=s1+a[i][j];
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
            s2=s2+b[i][j];
        }
    }
    printf("\n");
    printf("Matrix 1st is:-\n");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    if(n1==m1)
    { printf("Transpose of 1st matrix is:\n");
      for(i=0;i<n1;i++)
      {
          for(j=0;j<m1;j++)
          {
              printf("%d ",a[j][i]);
          }
          printf("\n");
      }
    }
    else if(n1!=m1)
    { printf("Transpose not possible"); }
    printf("\n");
    printf("Sum of elements is: %d\n",s1);
    printf("\n");
    printf("Matrix 2nd is:-\n");
    for(i=0;i<n2;i++)
    {
        for(j=0;j<m2;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    if(n2==m2)
    { printf("Transpose of matrix 2nd is:\n");
      for(i=0;i<n1;i++)
      {
          for(j=0;j<m1;j++)
          {
              printf("%d ",b[j][i]);
          }
          printf("\n");
      } 
    }
    else if(n2!=m2)
    { printf("Transpose not possible."); }
    printf("\n");
    printf("Sum of elements is: %d\n",s2);
    printf("\n");
    if((n1==n2)&&(m1==m2))
    {
        printf("Sum of matrices is:\n");
        for(i=0;i<n1;i++)
        {
          for(j=0;j<m1;j++)
          {
            s[i][j]=a[i][j]+b[i][j];
            printf("%d ",s[i][j]);
          }
          printf("\n");
        }
    }
    else if((n1!=n2)||(m1!=m2))
    {
      printf("Sum of matrices not possible.");
    }
}