#include <stdio.h>

#define CAPACITY 5

struct Queue {
    int arr[CAPACITY];
    int front;
    int rear;
};

void init_queue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int is_full(struct Queue *q) {
    return q->rear == CAPACITY - 1;
}

int is_empty(struct Queue *q) {
    return q->front > q->rear;
}

void enqueue(struct Queue *q, int val) {
    if (is_full(q)) {
        printf("Queue Overflow\n");
        return;
    }
    q->arr[++(q->rear)] = val;
}

int dequeue(struct Queue *q) {
    if (is_empty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->arr[(q->front)++];
}

int main() {
    struct Queue q;
    init_queue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    return 0;
}
