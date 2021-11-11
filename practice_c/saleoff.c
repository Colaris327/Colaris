#include <stdio.h>
/*每人300，超過3000打八折*/
int main() {
    int number, total;
    printf("Please enter the number of customers: ");
    scanf("%d", &number);
    if (number*300 >= 3000) {
        total = number*300*0.8;
    }
    if (number*300 < 3000) {
        total = number*300;
    }
    printf("Total: %d.\n", total);
    return 0;
}