#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int count_nodes(struct Node *head) {
    int count = 0;
    struct Node *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

int main() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 5;
    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 10;
    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->data = 15;
    head->next->next->next = NULL;

    printf("Total node count: %d\n", count_nodes(head));

    free(head->next->next);
    free(head->next);
    free(head);
    return 0;
}
