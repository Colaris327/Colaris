#include <stdio.h> \\找出N的所有正因數

int main() {
    int N, i;
    printf("N = ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        if (N % i == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}