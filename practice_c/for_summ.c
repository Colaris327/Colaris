#include <stdio.h> \\從1連加到指定數字

int main() {
    int num, sum = 0, number;
    printf("Enter your number:");
    scanf("%d", &number);
    for (num = 1; num <= number; num++) {
        sum = sum + num;
    }
    printf("%d\n", sum);
    return 0;
}