#include <stdio.h>

void merge_sorted_arrays(int a[], int n1, int b[], int n2, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < n1) {
        c[k++] = a[i++];
    }
    while (j < n2) {
        c[k++] = b[j++];
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {2, 5, 8, 12};
    int b[] = {1, 3, 7, 9, 15};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    int c[100];
    merge_sorted_arrays(a, n1, b, n2, c);
    printf("Merged array: ");
    print_array(c, n1 + n2);
    return 0;
}
