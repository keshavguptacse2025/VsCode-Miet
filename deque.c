#include <stdio.h>

#define MAX 5

struct Deque {
    int arr[MAX];
    int front;
    int rear;
    int size;
};

void init_deque(struct Deque *dq) {
    dq->front = -1;
    dq->rear = 0;
    dq->size = 0;
}

int is_full(struct Deque *dq) {
    return dq->size == MAX;
}

int is_empty(struct Deque *dq) {
    return dq->size == 0;
}

void insert_front(struct Deque *dq, int val) {
    if (is_full(dq)) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = val;
    dq->size++;
}

void insert_rear(struct Deque *dq, int val) {
    if (is_full(dq)) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = val;
    dq->size++;
}

int delete_front(struct Deque *dq) {
    if (is_empty(dq)) {
        printf("Deque Underflow\n");
        return -1;
    }
    int val = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    dq->size--;
    return val;
}

int delete_rear(struct Deque *dq) {
    if (is_empty(dq)) {
        printf("Deque Underflow\n");
        return -1;
    }
    int val = dq->arr[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
    dq->size--;
    return val;
}

int main() {
    struct Deque dq;
    init_deque(&dq);
    insert_rear(&dq, 10);
    insert_rear(&dq, 20);
    insert_front(&dq, 5);
    printf("Deleted front: %d\n", delete_front(&dq));
    printf("Deleted rear: %d\n", delete_rear(&dq));
    return 0;
}
