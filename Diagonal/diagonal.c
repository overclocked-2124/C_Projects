#include <stdio.h>

int main() {
    int rCount, cCount;
    scanf("%d%d", &rCount, &cCount);

    if (rCount == cCount) {
        int mat[rCount][cCount];

        for (int row = 0; row < rCount; row++) {
            for (int col = 0; col < cCount; col++) {
                scanf("%d", &mat[row][col]);
            }
        }

        printf("Primary diagonal elements:\n");
        for (int row = 0; row < rCount; row++) {
            for (int col = 0; col < cCount; col++) {
                if (row == col) {
                    printf("%d", mat[row][col]);
                }
            }
            printf("\n");
        }

        printf("Secondary diagonal elements:\n");
        for (int row = 0; row < rCount; row++) {
            for (int col = 0; col < cCount; col++) {
                if (row + col == cCount - 1) {
                    printf("%d", mat[row][col]);
                }
            }
            printf("\n");
        }

    } else {
        printf("Rows not equal to number of columns:");
    }

    return 0;
}
