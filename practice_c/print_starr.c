#include <stdio.h>

int main() {
    int array[5];
    int i, j;
    printf("Five numbers: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }
    int max = array[0];
    for (i = 0; i < 5; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    int maxx = max;

    int star[maxx][5];
    for (i = 0; i < maxx; i++) {
        for (j = 0; j < 5; j++) {
            star[i][j] = 0;
        }
    }
    for (i = 0; i < maxx; i++) {
        for (j = 0; j < 5; j++) {
            if (max <= array[j]) {
                star[i][j] = 1;
            }
        }
        max--;
    }

    for (i = 0; i < maxx; i++) {
        for (j = 0; j < 5; j++) {
            if (star[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}