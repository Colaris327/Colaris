#include <string.h>
#include <stdio.h>

int main() {
    char ans[80];
    char guess[2];
    printf("Your answer: ");
    scanf("%s", ans);
    int length = strlen(ans);
    char non[length];
    for (int i = 0; i < length; i++) {
        non[i] = '*';
    }
    while (1) {
        printf("Guess: ");
        scanf("%s", guess);
        for (int i = 0; i < 3; i++) {
            char *N = strstr(ans, guess);
            if (N == NULL) {
                break;
            } else {
                int U = N - &ans[0];
                ans[U] = '0';
                non[U] = guess[0];
            }
        }
        printf("%s\n", non);
        char *Q = strstr(non, "*");
        if (Q == NULL) {
            break;
        }
    }
    return 0;
}