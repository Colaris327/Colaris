#include <stdio.h>

int main() {
    int N, i;
    printf("How many * do you want: ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        printf("*");
    }
    return 0;
}