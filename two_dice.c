#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int count[11] = {0};
    int i;
    int dice1, dice2, sum;
    for(i = 1; i <= 100000; i++) {
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        sum = dice1 + dice2;
        count[sum - 2]++;
    }
    for (i = 2; i <= 12; i++) {
        printf("%d: %d\n", i, count[i - 2]);
    }
    return 0;
}