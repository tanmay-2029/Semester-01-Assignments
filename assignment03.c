#include <stdio.h>

int countWays(int n) {
    if (n <= 1)
        return 1;

    int ways = 0;
    for (int k = 1; k < n; k++) {
        ways += countWays(k) * countWays(n - k);
    }
    return ways;
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Number of ways = %d\n", countWays(n));
    return 0;
}