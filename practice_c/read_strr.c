#include <stdio.h>

void read(char[]);

int main() {
    char str[15];
    read(str);
    printf("%s\n", str);
    return 0;
}

void read(char str[]) {
    int i = 0;
    while(1) {
        scanf("%c", &str[i]);
        if (str[i] == '\n') {
            break;
        }
        i++;
    }
    str[i] = '\0';
}