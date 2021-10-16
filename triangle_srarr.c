#include <stdio.h> \\印三角形
int main() {
    int N;
    printf("N = ");
    scanf("%d", &N);
    int i, j;
    for (i = 1; i <= N ; i++) {
        for (j = 1; j <= i; j++) {
            if (i == j || i == N || j == 1) {
                printf("*");
            } else {
                printf(" ");
            }

        }
        printf("\n");
    }
    return 0;
}