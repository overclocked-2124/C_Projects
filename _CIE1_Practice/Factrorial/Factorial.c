#include<stdio.h>


int fact(int n){
    if(n==1 || n==0){
        return(1);
    }
    else{
        return(n* fact(n-1));
    }
}

int main(){
    int n , factorial;
    printf("Enter the number to find factorail of: ");
    scanf("%d",&n);
    factorial = fact(n);
    printf("The factorial of %d is : %d",n,factorial);
    return(0);
}
