#include <stdio.h>
int main()
{
    int n,m,a[100][100],i,j,r=0,c=0;
    printf("Enter row and col:-\n");
    scanf("%d%d",&n,&m);
    printf("Enter elements:-\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {   r=0;
        for(j=0;j<m;j++)
        {
            r=r+a[i][j];
        }
        printf("sum of row %d = %d\n",i+1,r);
    }
    for(j=0;j<m;j++)
    {   c=0;
        for(i=0;i<n;i++)
        {
            c=c+a[i][j];
        }
        printf("sum of column %d = %d\n",j+1,c);
    }
}