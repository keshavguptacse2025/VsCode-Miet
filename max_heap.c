#include <stdio.h>

#define MAX 100

struct MaxHeap {
    int arr[MAX];
    int size;
};

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void max_heapify(struct MaxHeap *h, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < h->size && h->arr[left] > h->arr[largest]) largest = left;
    if (right < h->size && h->arr[right] > h->arr[largest]) largest = right;
    if (largest != i) {
        swap(&h->arr[i], &h->arr[largest]);
        max_heapify(h, largest);
    }
}

void insert_max_heap(struct MaxHeap *h, int val) {
    if (h->size == MAX) return;
    int i = h->size++;
    h->arr[i] = val;
    while (i != 0 && h->arr[(i - 1) / 2] < h->arr[i]) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extract_max(struct MaxHeap *h) {
    if (h->size <= 0) return -1;
    if (h->size == 1) return h->arr[--(h->size)];
    int root = h->arr[0];
    h->arr[0] = h->arr[--(h->size)];
    max_heapify(h, 0);
    return root;
}

int main() {
    struct MaxHeap h;
    h.size = 0;
    insert_max_heap(&h, 30);
    insert_max_heap(&h, 10);
    insert_max_heap(&h, 50);
    insert_max_heap(&h, 5);
    printf("Extracted max: %d\n", extract_max(&h));
    printf("Extracted max: %d\n", extract_max(&h));
    return 0;
}
