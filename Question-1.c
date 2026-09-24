#include <stdio.h>

void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int n, int value, int pos) {
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    return n + 1;
}

int delete(int arr[], int n, int pos) {
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;

    printf("Traversal: ");
    traverse(arr, n);

    n = insert(arr, n, 25, 2);
    printf("After Insertion: ");
    traverse(arr, n);

    n = delete(arr, n, 3);
    printf("After Deletion: ");
    traverse(arr, n);

    return 0;
}

