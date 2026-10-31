#include <stdio.h>

#define MAX 10

void multiply_matrices(int r1, int c1, int a[MAX][MAX], int r2, int c2, int b[MAX][MAX], int res[MAX][MAX]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
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
    int r1 = 2, c1 = 3;
    int a[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}};
    int r2 = 3, c2 = 2;
    int b[MAX][MAX] = {{7, 8}, {9, 1}, {2, 3}};
    int res[MAX][MAX];
    multiply_matrices(r1, c1, a, r2, c2, b, res);
    printf("Matrix Product:\n");
    print_matrix(r1, c2, res);
    return 0;
}
