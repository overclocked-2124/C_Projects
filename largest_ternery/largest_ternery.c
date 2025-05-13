//program to find largest of 3 numbers using ternary operator
#include <stdio.h>

int main() {
    int a, b, c, largest;

    printf("Please enter numbers a, b, c respectively: ");
    scanf("%d%d%d", &a, &b, &c);

    largest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

    printf("The largest number is: %d\n", largest);

    return 0;
}
