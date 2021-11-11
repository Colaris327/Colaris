#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct listnode {
    int data;
    struct listnode *next;
} Listnode;

void print_l(Listnode * head) {
    for (; head != NULL; head = head->next) {
        printf("%d", head->data);
    }
}

int main() {
    int i;
    int array[5];
    for (i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }
    Listnode *head;
    Listnode *previous = NULL;
    for (i = 0; i < 5; i++) {
        head = (Listnode *)malloc(sizeof(Listnode));
        assert(head != NULL);
        head->data = array[i];
        head->next = previous;
        previous = head;
    }
    print_l(head);
    return 0;
}