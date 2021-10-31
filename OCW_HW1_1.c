#include <stdio.h>

//print n*n magic square

int main() {
    int i, j, p, q, n = 5;
    int arr_3[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr_3[i][j] = 0;
        }
    }
    i = 0;
    j = n / 2;
    int num = 1;
    arr_3[0][n / 2] = num;
    for (int k = 0; k < n * n; k++) {
        num++;
        p = i;
        q = j;
        i--;
        j--;
        if (i < 0) {
            i += n;
        } else if (i > n - 1) {
            i -= n;
        }
        if (j < 0) {
            j += n;
        } else if (j > n - 1) {
            j -= n;
        }
        if (arr_3[i][j] == 0) {
            arr_3[i][j] = num;
        } else {
            i = p + 1;
            j = q;
            arr_3[i][j] = num;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr_3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
