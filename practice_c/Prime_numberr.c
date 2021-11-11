#include <stdio.h>
int main() {
    int N, i, count = 0;
    printf("Enter your number: ");
    scanf("%d", &N);
    for (i = 2; i < N && count < 1; i++) {
        if (N % i == 0) {
            count++;
        }
    }
    if (count == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}