#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];

    printf("\x1b[2J");   // Clear screen

    for (;;) {
        memset(b, 32, 1760);
        memset(z, 0, 1760);

        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                float sini = sin(i), cosi = cos(i);
                float sinj = sin(j), cosj = cos(j);
                float sinA = sin(A), cosA = cos(A);
                float sinB = sin(B), cosB = cos(B);

                float h = cosj + 2;
                float D = 1 / (sini * h * sinA + sinj * cosA + 5);
                float t = sini * h * cosA - sinj * sinA;

                int x = 40 + 30 * D * (cosi * h * cosB - t * sinB);
                int y = 12 + 15 * D * (cosi * h * sinB + t * cosB);
                int o = x + 80 * y;

                int N = 8 * ((sinj * sinA - sini * cosj * cosA) * cosB
                             - sini * cosj * sinA - sinj * cosA
                             - cosi * cosj * sinB);

                if (y > 0 && y < 22 && x > 0 && x < 80 && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[(N > 0 ? N : 0)];
                }
            }
        }

        printf("\x1b[H");
        for (k = 0; k < 1760; k++) {
            putchar(k % 80 ? b[k] : '\n');
        }

        A += 0.04;
        B += 0.02;
        usleep(30000);
    }

    return 0;
}