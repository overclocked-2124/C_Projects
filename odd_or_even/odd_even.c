//This is a programn to find if a number is odd or even.

#include <stdio.h>

int main(){
    int a,rem;

    printf("Enter the number:");
    scanf("%d",&a);
    rem=a%2;

    if(rem==0){
        printf("Even\n");
    }
    else{
        printf("Odd\n");
    }
}

