#include <stdio.h>
int main() {
    int guess, answer = 4;
    printf("Please enter your guess: ");
    scanf("%d", &guess);
    if (guess > answer) {
        printf("Too large\n");
    } else if (guess < answer) {
        printf("Too small\n");
    } else {
        printf("Correct");
    }
    return 0;
}