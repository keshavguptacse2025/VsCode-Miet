#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void traverse(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
    n1->data = 100;
    n1->next = n2;
    n2->data = 200;
    n2->next = n3;
    n3->data = 300;
    n3->next = NULL;
    printf("Linked list traversal: ");
    traverse(n1);
    free(n3);
    free(n2);
    free(n1);
    return 0;
}
