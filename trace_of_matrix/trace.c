#include <stdio.h>

int main() {
    int rows, cols, sumPrimary = 0, sumSecondary = 0;
    scanf("%d%d", &rows, &cols);
    if (rows == cols) {
        int mat[rows][cols];
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                scanf("%d", &mat[r][c]);

        for (int i = 0; i < rows; i++) {
            sumPrimary   += mat[i][i];
            sumSecondary += mat[i][cols - 1 - i];
        }

        printf("Primary diagonal sum: %d\n", sumPrimary);
        printf("Secondary diagonal sum: %d\n", sumSecondary);
    } else {
        printf("Rows not equal to number of columns:");
    }
    return 0;
}
