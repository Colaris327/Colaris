#include <stdio.h>
#include <string.h>

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
    struct student john;
    struct student *ptr = &john;
    strcpy(ptr->name, "John Smith");
    ptr->id = 12345;
    strcpy(ptr->phone, "1234567");
    ptr->grade[0] = 4.0;
    ptr->grade[1] = 3.9;
    ptr->grade[2] = 3.8;
    ptr->grade[3] = 3.6;
    ptr->birth_year = 2000;
    ptr->birth_month = 1;
    ptr->birth_day = 1;
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