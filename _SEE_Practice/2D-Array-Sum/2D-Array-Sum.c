#include <stdio.h>

int main(){
    int a[10][10] ,b[10][10],c[10][10],n,m;

    printf("Enter the size of matrix: ");
    scanf("%d%d",n,m);

    printf("Enter elements of maxtrix 1: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter elements of maxtrix 2: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&b[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return(0);
}