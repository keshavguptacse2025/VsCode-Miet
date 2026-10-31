#include <stdio.h>

int delete_at(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        return 0;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    return 1;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {10, 20, 25, 30, 40, 50};
    int n = 6;
    printf("Initial array: ");
    print_array(arr, n);
    delete_at(arr, &n, 2);
    printf("After deletion at index 2: ");
    print_array(arr, n);
    return 0;
}
