#include <iostream>
#include <ctime>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Quick(int *arr, int left, int right) {
    int pivot = arr[left];
    int l = left, r = right + 1;
    if (left < right) {
        do {
            do {
                l++;
            } while (l <= right && arr[l] < pivot);
            do {
                r--;
            }  while (r >= left && arr[r] > pivot);
            if (l < r) {
                swap(arr[l], arr[r]);
            }
        } while (l < r);
        swap(arr[left], arr[r]);
        Quick(arr, left, r - 1);
        Quick(arr, r + 1, right);
    }
}

int main() {
    int array[10] = {0};
    cout << "Before: ";
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "After: ";
    Quick(array, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    return 0;
}