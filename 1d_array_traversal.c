#include <stdio.h>

void traverse_forward(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void traverse_backward(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 24, 36, 48, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Forward traversal: ");
    traverse_forward(arr, n);
    printf("Backward traversal: ");
    traverse_backward(arr, n);
    return 0;
}
