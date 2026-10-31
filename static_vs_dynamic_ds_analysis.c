#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50000

struct Node {
    int val;
    struct Node *next;
};

void analyze_static_array() {
    clock_t start = clock();
    int *arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        arr[i] = i * 2;
    }
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    size_t memory_bytes = N * sizeof(int);
    printf("--- Static/Contiguous Array ---\n");
    printf("Elements: %d\n", N);
    printf("Memory Used: %zu bytes\n", memory_bytes);
    printf("Sum: %lld\n", sum);
    printf("Execution Time: %f seconds\n\n", time_taken);
    free(arr);
}

void analyze_dynamic_linked_list() {
    clock_t start = clock();
    struct Node *head = NULL;
    struct Node *tail = NULL;
    for (int i = 0; i < N; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->val = i * 2;
        newNode->next = NULL;
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    long long sum = 0;
    struct Node *curr = head;
    while (curr) {
        sum += curr->val;
        curr = curr->next;
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    size_t memory_bytes = N * sizeof(struct Node);
    printf("--- Dynamic Linked List ---\n");
    printf("Elements: %d\n", N);
    printf("Memory Used: %zu bytes\n", memory_bytes);
    printf("Sum: %lld\n", sum);
    printf("Execution Time: %f seconds\n\n", time_taken);

    curr = head;
    while (curr) {
        struct Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    printf("Performance Analysis: Static Contiguous Array vs Dynamic Linked List\n\n");
    analyze_static_array();
    analyze_dynamic_linked_list();
    printf("Conclusion:\n");
    printf("1. Contiguous arrays offer lower memory overhead and better cache locality.\n");
    printf("2. Linked lists allocate dynamically with pointer overhead and non-contiguous memory access.\n");
    return 0;
}
