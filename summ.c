#include <stdio.h>
int main() {
    int number, sum = 0, count = 0;
    float average;
    printf("Please enter the numbers (0: quit) : ");
    scanf("%d", &number);
    if (number == 0) {
        printf("Average is N/A\n");
    } else {
        while (number != 0) {
            sum = sum + number;
            scanf("%d", &number);
            count = count + 1;
        }
    average = (float) sum / count;
    printf("Average is : %f\n", average);
    return 0;
    }
}