#include <stdio.h>

int maxx(int a, int b);

int main() {
    int a, b, max;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("max = %d", maxx(a, b));
    return 0;
}
int maxx(int a, int b) {
    int max;
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    return max;
}