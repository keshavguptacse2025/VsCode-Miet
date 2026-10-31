#include <stdio.h>

#define SIZE 5

struct CircularQueue {
    int arr[SIZE];
    int front;
    int rear;
};

void init_queue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int is_full(struct CircularQueue *q) {
    return (q->rear + 1) % SIZE == q->front;
}

int is_empty(struct CircularQueue *q) {
    return q->front == -1;
}

void enqueue(struct CircularQueue *q, int val) {
    if (is_full(q)) {
        printf("Queue Full\n");
        return;
    }
    if (is_empty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % SIZE;
    }
    q->arr[q->rear] = val;
}

int dequeue(struct CircularQueue *q) {
    if (is_empty(q)) {
        printf("Queue Empty\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    return val;
}

int main() {
    struct CircularQueue q;
    init_queue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Dequeued: %d\n", dequeue(&q));
    enqueue(&q, 40);
    printf("Dequeued: %d\n", dequeue(&q));
    return 0;
}
