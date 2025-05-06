//This is the program to check if array is sorted in accending order
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

    int sorted = 1;  
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            sorted = 0;
            break;
        }
    }

    if (sorted) {
        printf("The array is sorted in accending order.\n");
    } else {
        printf("The array is not sorted.\n");
    }
    return 0;
}
