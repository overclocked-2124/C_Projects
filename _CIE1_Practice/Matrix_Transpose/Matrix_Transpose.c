#include<stdio.h>

void transpose(int n,int m,int arr[n][m]){
    int temp;

    for (int i=0;i<n;i++){
        for (int j =0 ; j<m;j++){
            if(i>j){
                temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
    }
}

int main(){
    int n,m;
    printf("Enter the size of the matrix in form n X m:");
    scanf("%d%d",&n,&m);
    int mat[n][m];
    printf("Please enter the array elements: ");
    for(int i =0 ; i<n ; i++){
        for(int j =0 ; j<m ; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n");printf("\n");
    for(int i =0 ; i<n ; i++){
        for(int j =0 ; j<m ; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    
    transpose(n,m,mat);

    printf("\n");printf("\n");
    for(int i =0 ; i<n ; i++){
        for(int j =0 ; j<m ; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    return(0);
}