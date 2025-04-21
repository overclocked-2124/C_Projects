//program to check palindrome

#include <stdio.h>
#include <math.h>

int main() {
    int x, n, check, pal = 0, digit = 0;
    printf("Enter an integer: ");
    scanf("%d", &x);

    if (x == 0) {
        printf("True\n");
        return 0;
    }
    if (x < 0 || x % 10 == 0) {
        printf("False\n");
        return 0;
    }

    n = x;
    check = x;
    while (n != 0) {
        n = n / 10;
        digit++;
    }
    n = x;
    while (digit > 0) {
        pal += (n % 10) * pow(10, digit - 1);
        n = n / 10;
        digit--;
    }
    if (check == pal)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
