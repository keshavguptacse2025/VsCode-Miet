#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert_end(struct Node **head, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void delete_at_pos(struct Node **head, int pos) {
    if (*head == NULL || pos < 1) return;
    if (pos == 1) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node *curr = *head;
    for (int i = 1; i < pos - 1 && curr->next != NULL; i++) {
        curr = curr->next;
    }
    if (curr->next == NULL) return;
    struct Node *temp = curr->next;
    curr->next = temp->next;
    free(temp);
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
    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);
    insert_end(&head, 40);
    printf("Initial list: ");
    display(head);
    delete_at_pos(&head, 2);
    printf("After deleting at position 2: ");
    display(head);
    return 0;
}
