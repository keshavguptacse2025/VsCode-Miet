#include <stdio.h>

void solve_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 0) return;
    solve_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    solve_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3;
    printf("Tower of Hanoi solution for %d disks:\n", n);
    solve_hanoi(n, 'A', 'C', 'B');
    return 0;
}
