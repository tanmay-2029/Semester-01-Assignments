#include <stdio.h>

void drawHouse() {
    int i, j;

    /* Roof */
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 3 - i; j++)
            printf(" ");
        for (j = 1; j <= 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }

    /* Ceiling */
    printf("*****\n");

    /* Walls */
    for (i = 1; i <= 3; i++) {
        printf("*   *\n");
    }

    /* Base */
    printf("*****\n");
}

int main() {
    drawHouse();
    return 0;
}