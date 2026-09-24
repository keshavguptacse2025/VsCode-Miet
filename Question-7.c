#include <stdio.h>

int main() {
    int r = 2, c = 2;
    int a[2][2] = {{1, 2}, {3, 4}};
    int trans[2][2];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            trans[j][i] = a[i][j];
        }
    }

    printf("Result of Transpose:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
