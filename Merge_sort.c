#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int left, int mid, int right) {
    int temp[10];
    for (int i = left; i <= right; i++) {
        temp[i] = array[i];
    }
    int k = left, m = mid + 1;
    while (left <= mid && m <= right) {
        if (temp[left] <= temp[m]) {
            array[k++] = temp[left++];
        } else {
            array[k++] = temp[m++];
        }
    }
    if (left > mid) {
        for (int t = m; t <= right; t++) {
            array[t] = temp[t];
        }
    } else {
        for (int t = left; t <= mid; t++) {
            array[k++] = temp[t];
        }
    }
}

void mergesort(int array[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergesort(array, left, mid);
        mergesort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main() {
    int i;
    int array[10] = {0};
    printf("Before: ");
    for (i = 0; i < 10; i++) {
        array[i] = rand() % 10;
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("After: ");
    mergesort(array, 0, 9);
    for (i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}