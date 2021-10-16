#include <stdio.h>//產生隨機不重複的十個數字
#include <stdlib.h>
#include <time.h>

int main () {
    int i, j, k, ar[10];
    srand(time(0));
    for (i = 0; i < 10; i++) {
        do {
            ar[i] = rand() % 10 + 1;
            for (j = 0; j < i; j++) {
                k = 0;
                if (ar[j] == ar [i]) {
                    k = 1;
                    break;
                }
            }
        } while (k == 1);
        printf("%d ", ar[i]);
    }
    return 0;
}