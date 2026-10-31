#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {23, 45, 12, 78, 56, 89, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 78;
    int pos = linear_search(arr, n, key);
    if (pos != -1) {
        printf("Key %d found at index %d\n", key, pos);
    } else {
        printf("Key %d not found\n", key);
    }
    return 0;
}
