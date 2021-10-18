#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//random walk to 4 directions

int main() {
    srand(time(0));
    int i, j;
    char array[10][10];
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            array[i][j] = '.';
        }
    }

    char AA = 'A';
    array[0][0] = AA;
    int count = 0;//when you can't go the 4 directions, it will count to 1000 to stop the loop
    int a = 1;
    i = 0;
    j = 0;
    while(AA != 'Z' && count < 1000) {
        while (count < 1000 && a != 0) {
            count++;
            int di = rand() % 4;//choose a direction
            switch (di) {
                case 0: 
                    i++;//go down
                    break;
                case 1:
                    i--;//go up
                    break;
                case 2:
                    j++;//go right
                    break;
                case 3:
                    j--;//go left
                    break;
            }
            //check that you can go forward or not.
            //if not, return the value
            if (i < 0) {
                i++;
            } else if (i > 9) {
                i--;
            } else if (j < 0) {
                j++;
            } else if (j > 9){
                j--;
            } else if (array[i][j] == '.') {
                a = 0;//stop the loop
            } else {
                switch (di) {
                    case 0: 
                        i--;
                        break;
                    case 1:
                        i++;
                        break;
                    case 2:
                        j--;
                        break;
                    case 3:
                        j++;
                        break;
                } 
            }
        }
        a++;
        if (count < 1000) {
            AA = AA + 1;
            array[i][j] = AA;
        } else {
            array[i][j] = AA;
        }
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}
