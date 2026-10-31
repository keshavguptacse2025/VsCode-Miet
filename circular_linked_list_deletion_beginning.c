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

void delete_beginning(struct Node **last) {
    if (*last == NULL) return;
    struct Node *head = (*last)->next;
    if (head == *last) {
        free(head);
        *last = NULL;
        return;
    }
    (*last)->next = head->next;
    free(head);
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
    delete_beginning(&last);
    printf("After deleting from beginning: ");
    display(last);
    return 0;
}
