#include <stdio.h> \\找錢(100以內)
int main() {
    int i, j, k, l, N;
    scanf("%d", &N);
    i = (N >= 50);
    j = (N - 50 * i) / 10;
    k = ((N - 50 * i) - 10 * j) / 5;
    l = (N - 50 * i) - 10 * j - 5 * k;
    printf("%d\n%d\n%d\n%d\n", i, j, k, l);
    return 0;
}