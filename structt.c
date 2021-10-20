#include <stdlib.h>
#include <stdio.h>

struct student {
    char name[20];
    int id;
    char phone[10];
    double grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
};

int main() {
    struct student john = {"John Smith", 12345, "1234567", {4.0, 3.9, 3.8, 3.6}, 2000, 1, 1};
    printf("Name: %s\n", john.name);
    printf("ID: %d\n", john.id);
    printf("Phone: %s\n", john.phone);
    printf("Grade: ");
    for (int i = 0; i < 4; i++)
        printf("%f ", john.grade[i]);
    printf("\n");
    printf("Birth Year: %d\n", john.birth_year);
    printf("Birth Month: %d\n", john.birth_month);
    printf("Birth Day: %d\n", john.birth_day);
    return 0;
}