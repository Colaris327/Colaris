#include <stdio.h> \\韓信點兵僅顯示最大值
int main() {
    int i;
    printf("MAX: ");
    scanf("%d", &i);
    while (i > 0 && !(i % 3 ==2 && i % 5 == 3 && i % 7 == 2)) {
        i--;
    }
    if (i > 0) {
        printf("%d", i);
    }
    return 0;
}