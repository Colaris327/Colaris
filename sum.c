#include <stdio.h>

int sum(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return sum(n - 1) + n;
    }
}

int main() {
    int a = sum(3);
    printf("%d", a);
}