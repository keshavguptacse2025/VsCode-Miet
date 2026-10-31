#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert_at_pos(struct Node **head, int pos, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *curr = *head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) {
        free(newNode);
        return;
    }
    newNode->next = curr->next;
    curr->next = newNode;
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
    insert_at_pos(&head, 1, 10);
    insert_at_pos(&head, 2, 30);
    insert_at_pos(&head, 2, 20);
    printf("List after insertion at position 2: ");
    display(head);
    return 0;
}
