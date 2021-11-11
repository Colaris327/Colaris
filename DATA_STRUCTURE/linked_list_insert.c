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
    printf("\n");
}

Listnode *insert(Listnode *head, int data) {//head is the most small one
    Listnode *current = (Listnode *)malloc(sizeof(Listnode));
    assert(current != NULL);
    Listnode *ptr;
    Listnode *last;
    current->data = data;
    if (head == NULL) {
        current->next = NULL;
        return current;
    }
    last = NULL;
    ptr = head;
    while (ptr != NULL && ptr->data < data) {
        last = ptr;
        ptr = ptr->next;
    }
    if (last == NULL) {//current is smaller than head
        current->next = head;
        return current;
    } else {
        current->next = last->next;
        last->next = current;
        return head;
    }
}

Listnode *delete(Listnode *head, int data) {
    Listnode *ptr, *last;
    if (head == NULL) {
        return NULL;
    }
    last = NULL;
    ptr = head;
    while (ptr != NULL && data != ptr->data) {
        last = ptr;
        ptr = ptr->next;
    }
    if (last == NULL) {
        ptr = head->next;
        free(head); 
        return ptr;
    }
    if (ptr == NULL) {
        return head;
    } else {
        last->next = ptr->next;
        free(ptr);
        return head;
    }
}

int main() {
    int i;
    int ins[5], del[3];
    Listnode *head = NULL;
    for (i = 0; i < 5; i++) {
        scanf("%d", &ins[i]);
    }
    for (i = 0; i < 5; i++) {
        head = insert(head, ins[i]);
    }
    print_l(head);
    for (i = 0; i < 3; i++) {
        scanf("%d", &del[i]);
    }
    for (i = 0; i < 3; i++) {
        head = delete(head, del[i]);
    }
    print_l(head);
    return 0;
}