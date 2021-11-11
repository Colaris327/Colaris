#include <stdio.h>
int main() {
    int a, b, c, min;
    printf("Please enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    min = a;
    if (c < a && c <= b) {
        min = c;
    }
    if (b < a && b < c) {
        min = b;
    }
    printf("The minimum is %d.\n", min);
    return 0;
}