#include <stdio.h>
#include <stdlib.h>

struct PQNode {
    int data;
    int priority;
    struct PQNode *next;
};

struct PQNode *create_node(int data, int priority) {
    struct PQNode *newNode = (struct PQNode *)malloc(sizeof(struct PQNode));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void push(struct PQNode **head, int data, int priority) {
    struct PQNode *newNode = create_node(data, priority);
    if (*head == NULL || (*head)->priority > priority) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct PQNode *curr = *head;
    while (curr->next != NULL && curr->next->priority <= priority) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

int pop(struct PQNode **head) {
    if (*head == NULL) return -1;
    struct PQNode *temp = *head;
    int val = temp->data;
    *head = (*head)->next;
    free(temp);
    return val;
}

int peek(struct PQNode *head) {
    if (head == NULL) return -1;
    return head->data;
}

int main() {
    struct PQNode *pq = NULL;
    push(&pq, 100, 3);
    push(&pq, 200, 1);
    push(&pq, 300, 2);
    printf("Highest priority element: %d\n", peek(pq));
    printf("Popped: %d\n", pop(&pq));
    printf("Popped: %d\n", pop(&pq));
    return 0;
}
