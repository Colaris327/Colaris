#include <stdio.h>

char temp[30];
char *inttohex(int a){
    static int i = 0;
    if (a < 16) {
        if (a < 10) {
            temp[i] = '0' + a;
        } else {
            temp[i] = 'A' + a - 10;
        }
    } else {
        inttohex(a / 16);
        i++;
        a = a % 16;
        if (a < 10) {
            temp[i] = '0' + a;
        } else {
            temp[i] = 'A' + a - 10;
        }
    }
    temp[i + 1] = '\0';
    return temp;
}

int main() {
    int n;
    char *buff;
    printf("Number: ");
    scanf("%d", &n);
    buff = inttohex(n);
    printf("Hex: %s\n", buff);
    return 0;
}