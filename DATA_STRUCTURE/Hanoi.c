#include <stdio.h>

void Hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        printf("Put the %d plate from %c to %c\n", n, A, C);
    } else {
        Hanoi(n - 1, A, C, B);
        printf("Put the %d plate from %c to %c\n", n, A, C);
        Hanoi(n - 1, B, A, C);
    }
}

int main() {
    int n;
    printf("How many plates in Hanoi: ");
    scanf("%d", &n);
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}