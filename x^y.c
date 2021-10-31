#include <stdio.h>

//遞迴
int exp(int x, int y) {
    if (y == 1) {
        return x;
    } else {
        return exp(x, y - 1) * x;
    }
}

//迭代
int exp_I(int x, int y) {
    int count = 1;
    for (int i = 0; i  y; i++) {
        count = count * x;
    }
    return count;
}