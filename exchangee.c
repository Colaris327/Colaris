#include <stdio.h>
/*ABC to CAB*/
int main() {
    int a, b, c, t;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    printf("Before: %d %d %d\n", a, b, c);
    t = a;
    a = c;
    c = b;
    b = t;
    printf("After: %d %d %d\n", a, b, c);
    return 0;
}