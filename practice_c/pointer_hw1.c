#include <stdio.h>

int max(int *iptr[], int n) {
    int j, maxi;
    maxi = *iptr[0];
    for (j = 0; j < n; j++) {
        if (*iptr[j] > maxi) {
            maxi = *iptr[j];
        }
    }
    return maxi;
}

int main() {
    int i, array[10];
    int *iptr[10];

    for (i = 0; i < 10; i++) {
        scanf("%d",  &array[i]);
        iptr[i] = &array[i];
    }

    printf("\n%d\n", max(iptr, 10));
    return 0;
}