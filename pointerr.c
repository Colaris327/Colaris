#include <stdio.h>

/*指標概念_複製位址*/
void addone_indexx(int *n) {
    *n = *n + 1;
}

/*一般情況_複製值*/
void addone(int n) {
    n = n + 1;
}

int main() {
    int a = 3;
    int b = 3;
    addone_indexx(&a);
    addone(b);
    printf("%d\n", a);
    printf("%d\n", b);
    return 0;
}