#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert_end(struct Node **last, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    if (*last == NULL) {
        *last = newNode;
        newNode->next = newNode;
        return;
    }
    newNode->next = (*last)->next;
    (*last)->next = newNode;
    *last = newNode;
}

void delete_end(struct Node **last) {
    if (*last == NULL) return;
    struct Node *head = (*last)->next;
    if (head == *last) {
        free(head);
        *last = NULL;
        return;
    }
    struct Node *curr = head;
    while (curr->next != *last) {
        curr = curr->next;
    }
    curr->next = head;
    free(*last);
    *last = curr;
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
    insert_end(&last, 10);
    insert_end(&last, 20);
    insert_end(&last, 30);
    printf("Initial circular list: ");
    display(last);
    delete_end(&last);
    printf("After deleting from end: ");
    display(last);
    return 0;
}
