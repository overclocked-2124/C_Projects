// program to check if a number is an Armstrong number
#include <stdio.h>

int main(){
    int x, original, armstrong = 0;
    printf("Enter a number: ");
    scanf("%d", &x);

    original = x;
    while (x > 0) {
        armstrong +=(x%10)*(x%10)*(x%10);
        x = x / 10;
    }

    if(original==armstrong){
        printf("The given number is a Armstrong Number \n");
    }
    else{
        printf("The given number is not a Armstrong Number \n");
    }

    return 0;
}