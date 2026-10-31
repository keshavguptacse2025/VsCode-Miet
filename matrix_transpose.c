#include <stdio.h>

#define MAX 10

void transpose_matrix(int r, int c, int m[MAX][MAX], int trans[MAX][MAX]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            trans[j][i] = m[i][j];
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
    int m[MAX][MAX] = {{1, 4, 7}, {2, 5, 8}};
    int trans[MAX][MAX];
    transpose_matrix(r, c, m, trans);
    printf("Original Matrix:\n");
    print_matrix(r, c, m);
    printf("Transposed Matrix:\n");
    print_matrix(c, r, trans);
    return 0;
}
