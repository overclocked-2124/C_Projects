#include <stdio.h>

int fact(int n);

int main(){
    int n , factorial;

    printf("Enter the number to find factorial of: ");
    scanf("%d",&n);

    factorial = fact(n);

    printf("factorial of %d is %d.",n,factorial);
    return(0);
}

int fact(int n){
    if(n==1 || n==0){
        return(1);
    }
    else{
        return(n*fact(n-1));
    }
}