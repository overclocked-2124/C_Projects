#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int a[m][n],count=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0)
            {
                count++;
            }
        }
    }
    printf("Total number of non zero elements are:%d",count);
}