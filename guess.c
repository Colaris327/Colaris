#include <stdio.h>
int main() {
    int a = 4, guess;
    printf("Enter your guess:");
    scanf("%d", &guess);
    if (guess > a) {
        printf("Too large");
    }
    if (guess < a) {
        printf("Too small");
    }
    if (guess == a) {
        printf("Correct");
    }
    return 0;
}