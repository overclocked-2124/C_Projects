#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    if(m==n)
    {
    int a[m][n],b[m][n],c[m][n];
    printf("Enter the first matrix:");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter second matrix:");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("Summed matrix is:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",c[i][j]);
        }
        printf("\n");
    }
    }
    else
    {
        printf("Rows not equal to number of columns:");
    }
}
