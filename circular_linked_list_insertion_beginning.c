#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert_beginning(struct Node **last, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    if (*last == NULL) {
        *last = newNode;
        newNode->next = newNode;
        return;
    }
    newNode->next = (*last)->next;
    (*last)->next = newNode;
}

void display(struct Node *last) {
    if (last == NULL) {
        printf("Empty\n");
        return;
    }
    struct Node *curr = last->next;
    do {
        printf("%d -> ", curr->data);
        curr = curr->next;
    } while (curr != last->next);
    printf("(head)\n");
}

int main() {
    struct Node *last = NULL;
    insert_beginning(&last, 30);
    insert_beginning(&last, 20);
    insert_beginning(&last, 10);
    printf("Circular list after insertions at beginning: ");
    display(last);
    return 0;
}
