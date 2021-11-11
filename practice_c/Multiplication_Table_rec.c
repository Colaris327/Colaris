#include <stdio.h>

void mult(int i, int j) {
    if (i < 10) {
        if (j < 10) {
            printf("%d * %d = %d\n", i, j, i * j);
            mult(i, ++j);
        } else {
            mult(++i, 1);
        }
    }
}

int main() {
    mult(1, 1);
    return 0;
}