#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int *arr, int root, int n) {
    int k = arr[root];
    int j;
    for (j = 2 * root; j <= n; j *= 2) {
        if (j < n && arr[j] < arr[j + 1]) {// We will get error if j == n (after swap)
            j++;
        }
        if (arr[j] <= k) {
            break;
        }
        arr[j / 2] = arr[j];
    }
    arr[j / 2] = k;
}

void Heapsort(int *arr, int n) {// Heap will start from [1]
    for (int i = n / 2; i > 0; i--) {
        Heapify(arr, i, n);
    }
    for (int i = n; i > 1; i--) {
        swap(&arr[1], &arr[i]);
        Heapify(arr, 1, i - 1);
    }
}

int main() {
    int arr[10] = {0, 2, 5, 7, 4, 5, 9, 4, 1, 6};
    printf("Before: ");
    for (int i = 1; i < 10; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    Heapsort(arr, 10);
    printf("After:  ");
    for (int i = 1; i < 10; i++) {
        printf("%d", arr[i]);
    }
    return 0;
}