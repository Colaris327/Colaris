#include <stdio.h> \\空心長方形(類似座標化)
int main() {
    int N;
    printf("N = ");
    scanf("%d", &N);
    int i, j;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if (i == 1 || i == N || j == 1 || j == N) {
                printf ("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}