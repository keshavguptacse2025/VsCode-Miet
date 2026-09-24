#include <stdio.h>

void merge(int a[], int n1, int b[], int n2, int res[]) {
    int i, j;
    for (i = 0; i < n1; i++) {
        res[i] = a[i];
    }
    for (j = 0; j < n2; j++) {
        res[n1 + j] = b[j];
    }
}

int main() {
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};
    int res[6];

    merge(a, 3, b, 3, res);

    for (int i = 0; i < 6; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
