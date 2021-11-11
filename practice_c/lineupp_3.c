#include <stdio.h>
int main() {
    int a, b, c, t;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    printf("Before: %d %d %d\n", a, b, c);
    if (b < a) {
        t = a;
        a = b;
        b = t;
    }
    if (c < a) {
        t = c;
        c = a;
        a = t;
    }
    if (c < b) {
        t = c;
        c = b;
        b = t;
    }
    printf("After: %d %d %d", a, b, c);
    /*可跟三角形問題做結合*/
    return 0;
}