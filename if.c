#include <stdio.h>
/*if (表示式) {程式片段}*/
int main() {
    int a;
    printf("a = ");
    scanf("%d", &a);
    if (a > 4) {
        printf("a is larger than 4.\n");
    }
    if (a < 4) {
        printf("a is less than 4.\n");
    }
    if (a == 4) { if (a > 4) /*如果把一個等號刪掉，會使()內變為4，電腦會判斷為對*/
        printf("a is is equal to 4.\n");
    }
    return 0;
}