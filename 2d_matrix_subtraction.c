#include <stdio.h>

#define MAX 10

void subtract_matrices(int r, int c, int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
}

void print_matrix(int r, int c, int m[MAX][MAX]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r = 2, c = 3;
    int a[MAX][MAX] = {{9, 8, 7}, {6, 5, 4}};
    int b[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}};
    int res[MAX][MAX];
    subtract_matrices(r, c, a, b, res);
    printf("Matrix Difference:\n");
    print_matrix(r, c, res);
    return 0;
}
