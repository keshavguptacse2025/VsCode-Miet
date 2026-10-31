#include <stdio.h>

int insert_at(int arr[], int *n, int capacity, int pos, int val) {
    if (*n >= capacity || pos < 0 || pos > *n) {
        return 0;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
    return 1;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;
    printf("Initial array: ");
    print_array(arr, n);
    insert_at(arr, &n, 100, 2, 25);
    printf("After insertion at index 2: ");
    print_array(arr, n);
    return 0;
}
