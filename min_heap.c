#include <stdio.h>

#define MAX 100

struct MinHeap {
    int arr[MAX];
    int size;
};

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void min_heapify(struct MinHeap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < h->size && h->arr[left] < h->arr[smallest]) smallest = left;
    if (right < h->size && h->arr[right] < h->arr[smallest]) smallest = right;
    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        min_heapify(h, smallest);
    }
}

void insert_min_heap(struct MinHeap *h, int val) {
    if (h->size == MAX) return;
    int i = h->size++;
    h->arr[i] = val;
    while (i != 0 && h->arr[(i - 1) / 2] > h->arr[i]) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extract_min(struct MinHeap *h) {
    if (h->size <= 0) return -1;
    if (h->size == 1) return h->arr[--(h->size)];
    int root = h->arr[0];
    h->arr[0] = h->arr[--(h->size)];
    min_heapify(h, 0);
    return root;
}

int main() {
    struct MinHeap h;
    h.size = 0;
    insert_min_heap(&h, 30);
    insert_min_heap(&h, 10);
    insert_min_heap(&h, 50);
    insert_min_heap(&h, 5);
    printf("Extracted min: %d\n", extract_min(&h));
    printf("Extracted min: %d\n", extract_min(&h));
    return 0;
}
