#include <stdio.h>

void sel_sort(int array[], int N) {
    int i, j, ch;
    for (i = 0; i < N; i++) {
        int min = i;
        for (j = i + 1; j <= N; j++) {
            if (array[min] > array[j]) {
                min = j;
            }
        }
        if (min != i) {
            ch = array[i];
            array[i] = array[min];
            array[min] = ch;
        }
    }
}

int main() {
    int t, k;
    printf("How many numbers? ");
    scanf("%d", &k);
    int array[k];
    for (t = 0; t < k; t++) {
        printf("numbers: ");
        scanf("%d", &array[t]);
    }
    sel_sort(array, k);
    for (int j = 0; j < k; j++) {
        printf("%d\n", array[j]);
    }
    return 0;
}