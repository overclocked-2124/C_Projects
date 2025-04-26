//program to check if the given number is a perfect number
#include <stdio.h>

int main() {
    int num, sum = 0;
    scanf("%d", &num);
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    if (sum == num && num != 0) {
        printf("Perfect number\n");
    } else {
        printf("Not a perfect number\n");
    }
    return 0;
}

