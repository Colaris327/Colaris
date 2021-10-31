#include <stdio.h>

int BS(int *array, int x, const int left, const int right) {
    if (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] > x) {
            return BS(array, x, left, mid - 1);
        } else if (array[mid] < x) {
            return BS(array, x, mid + 1, right);
        } else {
            return mid;
        }
        return -1;
    }
}