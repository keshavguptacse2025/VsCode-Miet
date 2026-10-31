#include <stdio.h>

int binary_search(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {11, 22, 33, 44, 55, 66, 77, 88};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 55;
    int pos = binary_search(arr, n, key);
    if (pos != -1) {
        printf("Key %d found at index %d\n", key, pos);
    } else {
        printf("Key %d not found\n", key);
    }
    return 0;
}
