#include <stdio.h> \\印出1到10間不是3的倍數的偶數 \\for (初始式; 條件式; 迴圈式) {程式片段}

int main() {
    int num;
    for (num = 1; num <= 10; num++) {
        if (num % 2 == 0 && num % 3 != 0) {
            printf("%d\n", num);
        }
    }
    return 0;
}