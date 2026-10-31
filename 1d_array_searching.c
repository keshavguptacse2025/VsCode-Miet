#include <stdio.h>

int search_key(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {45, 12, 89, 34, 76, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 34;
    int idx = search_key(arr, n, target);
    if (idx != -1) {
        printf("Element %d found at index %d\n", target, idx);
    } else {
        printf("Element %d not found\n", target);
    }
    return 0;
}
