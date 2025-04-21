//program to find prime numbers between two numbers
#include <stdio.h>

int main() {
    int start, end, i, j, isPrime;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    for(i = start; i <= end; i++) {
        if(i == 1)
            continue;
        isPrime = 1;
        for(j = 2; j < i; j++) {
            if(i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if(isPrime)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
