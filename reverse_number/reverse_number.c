//Program to reverse a number
#include <stdio.h>

int main() {
    int x, original, reversed = 0;
    printf("Enter a number: ");
    scanf("%d", &x);

    original = x;
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x = x / 10;
    }

    printf("%d",reversed);
    return 0;
}
