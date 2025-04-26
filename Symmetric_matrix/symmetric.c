#include<stdio.h>
int main()
{
    int m,n,flag=0;
    scanf("%d%d",&m,&n);
    if(m==n)
    {
    int a[m][n],b[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                flag=1;
                break;
            }      
        }
    }
    if(flag==1)
    {
        printf("Matrix is not symmetric");
    }
    else
    {
        printf("Given matrix is symmetric");
    }
}
else
{
    printf("Rows not equal to number of columns:");
}
}
