#include <stdio.h>
int main() {
    int a, b, c, med;
    printf("Please enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    med = a;
    if (b <= c && b >= a || b >= c && b <= a) {
        med = b;
    }
    if (c <= b && c >= a || c >= b && c <= a) {
        med = c;
    }
    printf("The median is %d.\n", med);
    return 0;
}