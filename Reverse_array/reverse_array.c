//This is a program to reverse an array without using temp variable
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n / 2; i++) {
        arr[i]=arr[i]+arr[n-1-i];
        arr[n-1-i]=arr[i]-arr[n-1-i];
        arr[i]=arr[i]-arr[n-1-i];
    }

    printf("Reversed array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
