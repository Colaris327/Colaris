#include <stdio.h>
#include <stdlib.h>
//print n! (to prevent for int_error, use array to avoid overflow)
//teacher says that I have to use pointer, but I don't know how. QQ
int main() {
    while(1) {
        int arr[100] = {0};
        arr[99] = 1;
        int N;
        printf("Number: ");
        scanf("%d", &N);
        if (N == 0) {
            break;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 99; j >= 0 ; j--) {
                arr[j] = arr[j] * i;
            }
            for (int q = 99; q >= 0; q--) {
                if (arr[q] >= 10) {
                    arr[q - 1] = arr[q - 1] + arr[q] / 10;
                    arr[q] = arr[q] % 10;
                }
            }
            int count = 0;
            for (int k = 0; k <= 99; k++) {
                if (arr[k] != 0) {
                    count = k;
                    break;
                }
            }
            printf("%d! = ", i);
            for (int u = count; u <= 99; u++) {
                printf("%d", arr[u]);
            }
            printf("\n");
        }
    }
    return 0;
}