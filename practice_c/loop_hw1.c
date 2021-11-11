#include <stdio.h>
//two balls move in a x*y flat
int main() {
    int a = 1;
    int x, y, x1, y1, x2, y2, dx1, dy1, dx2, dy2, t;
    int i, j, q;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &x1);
    scanf("%d", &y1);
    scanf("%d", &x2);
    scanf("%d", &y2);
    scanf("%d", &dx1);
    scanf("%d", &dy1);
    scanf("%d", &dx2);
    scanf("%d", &dy2);
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        x1 += dx1;
        y1 += dy1;
        x2 += dx2;
        y2 += dy2;
        if (x1 == 0 || x1 == x) {
            dx1 = -dx1;
        }
        if (y1 == 0 || y1 == y) {
            dy1 = -dy2;
        }
        if (x2 == 0 || x2 == x) {
            dx2 = -dx2;
        }
        if (y2 == 0 || y2 == y) {
            dy2 = -dy2;
        }
        if (x1 == x2 && y1 == y2) {
            if (dx1 * dy1 * dx2 * dy2 == 1) {
                dx1 = -dx1;
                dy1 = -dy1;
                dx2 = -dx2;
                dy2 = -dy2;
            } else if (dx1 == dx2) {
                dy1 = -dy1;
                dy2 = -dy2;
            } else {
                dx1 = -dx1;
                dx2 = -dx2;
            }
        }
    }
    printf("%d %d\n", x1, y1);
    printf("%d %d\n", x2, y2);
    return 0;
}

