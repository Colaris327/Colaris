#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    *twenties = dollars / 20;
    *tens = (dollars - *twenties * 20) / 10;
    *fives = (dollars - *twenties * 20 - *tens * 10) / 5;
    *ones = dollars - *twenties * 20 - *tens * 10 - *fives * 5;
}

int main() {
    int dollars = 37;
    int twenty, ten, five, one;
    pay_amount(dollars, &twenty, &ten, &five, &one);
    printf("twenties: %d\n", twenty);
    printf("tens: %d\n", ten);
    printf("fives: %d\n", five);
    printf("ones: %d\n", one);
    return 0;
}