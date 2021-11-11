#include <stdio.h>
#include <string.h>

int main() {
    char str[80];
    char es[] = "es";
    char s[] = "s";
    printf("Enter: ");
    scanf("%s", &str);
    int N = strlen(str);
    if (str[N - 1] == 's' || str[N - 1] == 'z' || str[N - 1] == 'x' || (str[N - 1] == 'h' && str[N - 2] == 'c') || (str[N - 1] == 'h' && str[N - 2] == 's')) {
        strcat(str, es);
    } else if (str[N - 1] == 'y') {
        if (str[N - 2] == 'a' || str[N - 2] == 'e' || str[N - 2] == 'i' || str[N - 2] == 'o' || str[N - 2] == 'u' ) {
            strcat(str, s);
        } else {
            str[N - 1] = 'i';
            strcat(str, es);
        }
    } else {
        strcat(str, s);
    }
    printf("%s", str);
    return 0;
}