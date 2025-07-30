#include <stdio.h>

int main(){
    int num,n;

    printf("Enter the number to find tables of: ");
    scanf("%d",&num);
    printf("enter the number to find tables till:");
    scanf("%d",&n);

    for(int i =0; i<=n;i++){
        if((num*i)%7==0){
            continue;
        }
        printf("\n %d X %d = %d",num,i,num*i);
    }
}