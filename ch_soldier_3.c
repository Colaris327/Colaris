#include <stdio.h> \\韓信點兵找前三大的

int main() {
    int i, count = 1;
    for (i = 1000; i >= 1 && count <= 3; i--) {
        if (i % 3 ==2 && i % 5 == 3 && i % 7 == 2) {
            count++;
            printf("%d\n", i);
        }
    }
    return 0;
}