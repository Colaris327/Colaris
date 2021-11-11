#include <stdio.h>

int main() {
    int M, N, count;
    printf("Enter ther number of M: ");
    scanf("%d", &M);
    printf("Enter ther number of N: ");
    scanf("%d", &N);
    count = M;
    while (count <= N) {
        printf("%d\n", count);
        count = count + 1;
    }
    return 0;
}