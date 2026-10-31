#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *reverse_list(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    printf("Original list: ");
    display(head);
    head = reverse_list(head);
    printf("Reversed list: ");
    display(head);

    free(head->next->next);
    free(head->next);
    free(head);
    return 0;
}
