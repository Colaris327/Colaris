#include <stdio.h>
int main() {
    int a, b, max;
    printf("Please enter your first integer: ");
    scanf("%d", &a);
    printf("Please enter your second integer: ");
    scanf("%d", &b);
    max = a;
    if (b > a) {
        max = b;
    }
    printf("The maximum is %d.\n", max);
    return 0;
}