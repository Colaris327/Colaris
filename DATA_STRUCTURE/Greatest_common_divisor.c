#include <stdio.h>

//最大公因數(遞迴)
int GCD(int m, int n) {
    if (m % n == 0) {
        return n;
    } else {
        return GCD(n, m % n);
    }
}

//最大公因數(迭代)
int GCD_I(int m, int n) {
    while (m != 0 && n != 0) {
        if (m > n) {
            m = m % n;
        } else {
            n = n % m;
        }
        if (m == 0) {
            return n;
        } else {
            return m;
        }
    }
}

//最小公倍數
int LCM(int m, int n) {
    return m * n / GCD(m, n);
}

int main() {
    int a = GCD(12, 8);
    int aa = GCD_I(12, 8);
    printf("%d,%d\n", a, aa);
    int b = LCM(12, 8);
    printf("%d", b);
    return 0;
}