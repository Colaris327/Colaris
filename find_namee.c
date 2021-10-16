#include <stdio.h>

int main() {
    int id;
    printf("ID: ");
    scanf("%d", &id);
    switch (id) {
        case 2 :
            printf("John \n");
            break;
        case 13 :
            printf("Mary \n");
            break;
        case 16 :
            printf("Amy \n");
            break;
        case 23 :
            printf("Marcel \n");
            break;
        case 5 :
            printf("Vanoss \n");
            break;
        default :
            printf("Not found \n");
            break;
    }
    return 0;
}