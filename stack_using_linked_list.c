#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **top, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node *temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int peek(struct Node *top) {
    if (top == NULL) return -1;
    return top->data;
}

int main() {
    struct Node *top = NULL;
    push(&top, 100);
    push(&top, 200);
    push(&top, 300);
    printf("Top element: %d\n", peek(top));
    printf("Popped: %d\n", pop(&top));
    printf("Popped: %d\n", pop(&top));
    return 0;
}
