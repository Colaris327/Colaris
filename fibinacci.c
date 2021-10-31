#include <stdio.h>

//遞迴
int Fib_c(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return Fib_c(n - 1) + Fib_c(n - 2);
    }
}

//迴圈
int Fib_l(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int a = 0, b = 1, c;
        for (int i = 0; i <= n - 2; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

int main() {
    int n;
    printf("Number: ");
    scanf("%d", &n);
    printf("%d, %d", Fib_c(n), Fib_l(n));
    return 0;
}