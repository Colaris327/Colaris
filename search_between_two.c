#include <stdio.h>//先輸入10個數字，印出上下界所包含的數字

int main() {
    int num[10];
    int i;
    for (i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    while(1) {
        int LL, RR;
        printf("L: ");
        scanf("%d", &LL);
        printf("R: ");
        scanf("%d", &RR);
        printf("ANS: ");
        if (LL == 0 && RR == 0) {
            break;
        }
        for (i = 0; i < 10; i++) {
            if (num[i] >= LL && num[i] <= RR) {
                printf("%d ", num[i]);
            }
        }
        printf("\n");
    }
    return 0;
}