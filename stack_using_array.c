#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

struct Stack {
    int arr[CAPACITY];
    int top;
};

void init_stack(struct Stack *s) {
    s->top = -1;
}

int is_full(struct Stack *s) {
    return s->top == CAPACITY - 1;
}

int is_empty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int val) {
    if (is_full(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = val;
}

int pop(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(struct Stack *s) {
    if (is_empty(s)) return -1;
    return s->arr[s->top];
}

int main() {
    struct Stack s;
    init_stack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    return 0;
}
