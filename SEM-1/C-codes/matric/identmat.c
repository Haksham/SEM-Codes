#include<stdio.h>
int main()
{   int i,j,n,m,a[100][100],f=0;
    printf("Enter number of rows: \n");
    scanf("%d",&n);
    printf("Enter number of columns: \n");
    scanf("%d",&m);
    printf("Enter numbers:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("for %d row %d column:",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if((i==j)&&(a[i][j]!=1))
            {
                f=-1;
                break;
            }
            else if((i!=j)&&(a[i][j]!=0))
            {
                f=-1;
                break;
            }
        }    
    }
    if(f==0)
    {printf("identity");}
    else
    {printf("not.");}
}