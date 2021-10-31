#include <stdio.h>
//#define swap(a,b,t) ((t)=(a),(a)=(b),(b)=(t))

void swap(char *a, char *b) {
    char t;
    t = *a;
    *a = *b;
    *b = t;
}

void per(char *arr,const int m,const int n) {
    int t = 0;
    if (m == n) {
        for (int i = 0; i <= n; i++) {
            printf("%c", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = m; i <= n; i++) {
            swap(&arr[m], &arr[i]);
            per(arr, m + 1, n);
            swap(&arr[m], &arr[i]);
        }
    }
}

int main() {
    char arr[10];
    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'd';
    per(arr, 0, 2);
    return 0;
}