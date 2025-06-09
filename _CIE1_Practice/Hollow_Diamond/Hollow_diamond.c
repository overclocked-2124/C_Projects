#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of rows on the top half: ");
    scanf("%d",&n);

    for(int i = 1; i <=n;i++){
        
        for( int j=0;j<(n-i);j++){
            printf(" ");
        }
        if(i!=1){
            printf("*");
            for(int k = 0; k<(2*(i-2)+1);k++){
                printf(" ");
            }
            printf("*\n");
        }
        else{
        printf("*\n");
        }
    }
    
    for(int i = 1; i <n;i++){
        for( int j=0;j<(i);j++){
            printf(" ");
        }
        if(i!=(n-1)){
            printf("*");
            for(int k = 0; k<(2*((n-i)-2)+1);k++){
                printf(" ");
            }
            printf("*\n");
        }
        else{
        printf("*\n");
        }
    }
    return(0);
}