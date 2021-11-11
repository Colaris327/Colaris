#include <stdio.h> \\韓信點兵:挑出除3餘2，除5餘3，除7餘2的值

int main() {
    int i, max, min;
    printf("MAX = ");
    scanf("%d", &max);
    printf("MIN = ");
    scanf("%d", &min);
    for (i = min; i <= max; i++) {
        if (i % 3 ==2 && i % 5 == 3 && i % 7 ==2) {
            printf("%d\n", i);
        }
    }
    return 0;
}