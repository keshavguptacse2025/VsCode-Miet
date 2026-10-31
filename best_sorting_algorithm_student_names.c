#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 8
#define NAME_LEN 32

void bubble_sort_names(char arr[][NAME_LEN], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[NAME_LEN];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

void merge(char arr[][NAME_LEN], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    char L[n1][NAME_LEN];
    char R[n2][NAME_LEN];

    for (int i = 0; i < n1; i++) strcpy(L[i], arr[l + i]);
    for (int j = 0; j < n2; j++) strcpy(R[j], arr[m + 1 + j]);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k++], L[i++]);
        } else {
            strcpy(arr[k++], R[j++]);
        }
    }
    while (i < n1) strcpy(arr[k++], L[i++]);
    while (j < n2) strcpy(arr[k++], R[j++]);
}

void merge_sort_names(char arr[][NAME_LEN], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_names(arr, l, m);
        merge_sort_names(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void print_names(char arr[][NAME_LEN], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, arr[i]);
    }
}

int main() {
    char names[MAX_NAMES][NAME_LEN] = {
        "Suresh", "Aarav", "Pooja", "Deepak",
        "Ananya", "Rohan", "Bhavna", "Kiran"
    };

    printf("=== Performance Analysis: Best Sorting Algorithm for Student Names ===\n");
    printf("Candidate Algorithms Evaluation for Strings (Student Names):\n");
    printf("1. Bubble Sort: O(N^2 * L) - Inefficient for large rosters.\n");
    printf("2. Quick Sort: O(N log N * L) average, but O(N^2 * L) worst case and unstable.\n");
    printf("3. Merge Sort: O(N log N * L) guaranteed, stable, preserves ties (e.g. same name, diff roll number).\n");
    printf("4. MSD Radix Sort: O(N * L) linear, optimal for fixed alphabet large string lists.\n\n");
    printf("Selected Best General-Purpose Algorithm: Merge Sort (Guaranteed O(N log N) & Stable)\n\n");

    printf("Original Student Names List:\n");
    print_names(names, MAX_NAMES);

    merge_sort_names(names, 0, MAX_NAMES - 1);

    printf("\nSorted Student Names (via Merge Sort):\n");
    print_names(names, MAX_NAMES);

    return 0;
}
