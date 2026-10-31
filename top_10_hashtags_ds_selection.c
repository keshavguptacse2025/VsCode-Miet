#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 10
#define MAX_TAGS 1000

struct TagFrequency {
    char tag[64];
    int count;
};

struct MinHeap {
    struct TagFrequency data[K];
    int size;
};

void swap(struct TagFrequency *a, struct TagFrequency *b) {
    struct TagFrequency temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(struct MinHeap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->data[left].count < h->data[smallest].count) {
        smallest = left;
    }
    if (right < h->size && h->data[right].count < h->data[smallest].count) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&h->data[i], &h->data[smallest]);
        min_heapify(h, smallest);
    }
}

void insert_into_topk(struct MinHeap *h, const char *tag, int count) {
    if (h->size < K) {
        strcpy(h->data[h->size].tag, tag);
        h->data[h->size].count = count;
        int i = h->size++;
        while (i != 0 && h->data[(i - 1) / 2].count > h->data[i].count) {
            swap(&h->data[i], &h->data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    } else if (count > h->data[0].count) {
        strcpy(h->data[0].tag, tag);
        h->data[0].count = count;
        min_heapify(h, 0);
    }
}

int main() {
    struct TagFrequency stream[] = {
        {"#coding", 1450},
        {"#tech", 890},
        {"#ai", 3200},
        {"#datascience", 2100},
        {"#cprogramming", 670},
        {"#webdev", 1850},
        {"#opensource", 420},
        {"#algorithms", 1230},
        {"#software", 950},
        {"#cloud", 1120},
        {"#devops", 1340},
        {"#ml", 2890},
        {"#python", 2400},
        {"#systems", 510}
    };
    int stream_size = sizeof(stream) / sizeof(stream[0]);

    struct MinHeap top_k;
    top_k.size = 0;

    for (int i = 0; i < stream_size; i++) {
        insert_into_topk(&top_k, stream[i].tag, stream[i].count);
    }

    printf("=== DS Selection Analysis for Top 10 Hashtags ===\n");
    printf("Optimal DS: Hash Table (O(1) lookup & count update) + Min-Heap of size K (O(log K) maintenance)\n");
    printf("Time Complexity: O(N log K) instead of O(N log N) full sorting\n");
    printf("Space Complexity: O(U + K) where U is unique hashtags and K=10\n\n");
    printf("Top %d Trending Hashtags in Min-Heap:\n", top_k.size);
    for (int i = 0; i < top_k.size; i++) {
        printf("%d. %-16s : %d mentions\n", i + 1, top_k.data[i].tag, top_k.data[i].count);
    }
    return 0;
}
