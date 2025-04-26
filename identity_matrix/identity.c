#include <stdio.h>

int main() {
    int rowCount, colCount, invalidFlag = 0;
    scanf("%d%d", &rowCount, &colCount);
    if (rowCount == colCount) {
        int matrix[rowCount][colCount];
        for (int r = 0; r < rowCount; r++) {
            for (int c = 0; c < colCount; c++) {
                scanf("%d", &matrix[r][c]);
            }
        }
        for (int r = 0; r < rowCount; r++) {
            for (int c = 0; c < colCount; c++) {
                if ((r == c && matrix[r][c] != 1) ||
                    (r != c && matrix[r][c] != 0)) {
                    invalidFlag = 1;
                    break;
                }
            }
            if (invalidFlag) break;
        }
        if (invalidFlag)
            printf("Matrix is not identity matrix\n");
        else
            printf("Given matrix is an identity matrix\n");
    } else {
        printf("Rows not equal to number of columns\n");
    }
    return 0;
}
