#include <stdio.h>

int main() {
    int i, j, ch,array[5];
    for (i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (array[j] > array[j + 1]) {
                ch = array[j];
                array[j] = array[j + 1];
                array[j + 1] = ch;
            }
        }
    }
    for (i = 0; i < 5; i++) {
        printf("%d", array[i]);
    }
    return 0;
}