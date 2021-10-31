#include <stdio.h>

int main() {
    int array[2] = {3, 4};
    int target;
    printf("Target: ");
    scanf("%d", &target);
    int left = 0, right = sizeof(array) / sizeof(array[0]);
    int a;
    while(1) {
        if (left == right) {
            a = 0;
            break;
        }
        int mid = (left + right) / 2;
        if (array[mid] == target) {
            a = 1;
            break;
        }
        if (array[mid] < target) {
            left = mid + 1;
        } else if (array[mid] > target) {
            right = mid;
        }
    }
    printf("%d", a);
    return 0;
}