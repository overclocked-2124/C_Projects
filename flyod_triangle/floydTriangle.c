#include <stdio.h>

int main() {
    int n, i, j, val;
    scanf("%d", &n);
    val = 1;
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            printf("%d ", val);
            val = val +1;
        }
        printf("\n");
    }
    return 0;
}

