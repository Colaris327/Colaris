#include <stdio.h>//先輸入10個數字，找出最接近的數字
#include <stdlib.h>
int main() {
    int num[10];
    int i;
    for (i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    while (1) {
        int near, q;
        printf("Q: ");
        scanf("%d", &q);
        if (q == 0) {
            break;
        }
        for (i = 1; i <= 10; i++){
            if (abs(q - num[i]) < abs(q- num[0])) {
                near = num[i];
            }
        }
        printf("%d\n", near);
    }
        return 0;
}