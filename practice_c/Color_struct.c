#include <stdio.h>
#include "color.h"

#define N 128

int main() {
    int n, j, r, g, b;
    Color c[N], average;
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
        scanf("%d%d%d", &r, &g, &b);
        initColor(&c[j], r, g, b);
        printColor(&c[j]);
    }
    average = averageColor(c, n);
    printColor(&average);
    return 0;
}