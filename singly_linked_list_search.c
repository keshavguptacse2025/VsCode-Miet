#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int search_node(struct Node *head, int target) {
    int pos = 1;
    struct Node *curr = head;
    while (curr != NULL) {
        if (curr->data == target) {
            return pos;
        }
        curr = curr->next;
        pos++;
    }
    return -1;
}

int main() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 15;
    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 25;
    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->data = 35;
    head->next->next->next = NULL;

    int target = 25;
    int pos = search_node(head, target);
    if (pos != -1) {
        printf("Element %d found at node position %d\n", target, pos);
    } else {
        printf("Element %d not found\n", target);
    }

    free(head->next->next);
    free(head->next);
    free(head);
    return 0;
}
