#include <stdio.h>

int add_n(int *iptr, int n) {
    if (iptr == NULL) {
        return 0;
    } else {
        return *iptr += n;
    }
}

int main() {
    int i, j, k;
    scanf("%d", &i);
    scanf("%d", &j);
    printf("i = %d\n", i);
    k = add_n(NULL, j);
    printf("i = %d, k = %d\n", i, k);
    k = add_n(&i, j);
    printf("i = %d, k = %d\n", i, k);
    return 0;
}