#include <stdio.h>
int main() {
    int guess, answer = 4, count = 1;
    printf("Please enter your guess: ");
    scanf("%d", &guess);
    while (guess != answer) {
        if (guess > answer) {
        printf("Too large\n");
        } else {
        printf("Too small\n");
        }
        printf("Please enter your guess: ");
        scanf("%d", &guess);
        count = count + 1;
    }
    printf("Correct (%d)\n", count);
    return 0;
}