#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert_beginning(struct Node **head, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void display(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    insert_beginning(&head, 30);
    insert_beginning(&head, 20);
    insert_beginning(&head, 10);
    printf("List after inserting at beginning: ");
    display(head);
    return 0;
}
