#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void insert_beginning(struct Node **head, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void display_forward(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    insert_beginning(&head, 30);
    insert_beginning(&head, 20);
    insert_beginning(&head, 10);
    printf("Doubly linked list after insertions at beginning: ");
    display_forward(head);
    return 0;
}
