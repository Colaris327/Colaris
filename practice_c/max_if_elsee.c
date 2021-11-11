#include <stdio.h>
/*if那行會先做，若該行條件達成，便不會繼續運行*/
int main() {
    int a, b, c, max;
    printf("Please enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }
    printf("Max = %d\n", max);
    return 0;
}