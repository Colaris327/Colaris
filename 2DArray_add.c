#include <stdio.h>

void add (int **a, int **b, int **c, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *AA[3] = {A[0], A[1], A[2]};
    int B[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *BB[3] = {B[0], B[1], B[2]};
    int C[3][3];
    int *CC[3] = {C[0], C[1], C[2]};
    add(&AA[0], &BB[0], &CC[0], 3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}