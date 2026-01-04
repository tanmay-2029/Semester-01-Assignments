# C Programming Assignments

This repository contains **C programming assignments** that are :

* Printing without semicolon
* Pattern printing using loops and functions
* Recursion (Matrix Chain Multiplication problem)
* Donut.c explanation.

---

## Assignment 01

### Print Name Without Using Semicolon (`;`)

### Description

This program prints a name **without using a semicolon** by utilizing the return value of the `printf()` function inside an `if` condition.

### Code

```c
#include <stdio.h>

int main() {
    if (printf("Tanmay Singh 1st Year"))
    {
    }
    return 0;
}
```

### Output

```
Tanmay Singh 1st Year
```

---

## Assignment 02

### House Layout Using Loop and Function

### Description

This program designs a **simple house layout** using:

* User-defined function
* Nested `for` loops
* Pattern printing with `*`

### Code

```c
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
```

### Output

```
  *
 ***
*****
*   *
*   *
*   *
*****
```

---

## Assignment 03

### Recursion – Number of Ways to Multiply Matrices

### Description

This program uses **recursion** to calculate the number of ways `n` matrices can be multiplied.
The solution is based on the **Catalan number concept**.

### Code

```c
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
```

### Output

```
Enter number of matrices: 4
Number of ways = 5
```
---
## Assignment 04

# 🍩 donut.c — Explanation

## What is `donut.c`?

`donut.c` is a famous C program that displays a **rotating 3D donut (torus)** using **ASCII characters** in the terminal.

It was created by **Andy Sloane** and is popular for demonstrating how **3D graphics concepts** can be implemented using simple mathematics and C programming.

---

## Concepts Used in donut.c

### 1. Trigonometry

* Uses `sin()` and `cos()` functions
* Rotates the donut around two axes

### 2. 3D to 2D Projection

* Converts 3D coordinates `(x, y, z)` into 2D screen positions

### 3. Z-Buffer (Depth Buffer)

* Stores depth values
* Ensures closer points overwrite farther points

### 4. ASCII Shading

* Uses characters:

  ```
  . , - ~ : ; = ! * # $
  ```
* Brighter areas use denser characters

### 5. Infinite Animation Loop

* Continuously updates rotation angles
* Clears screen and redraws frame

---

## How the Donut is Created (Step-by-Step)

1. Mathematical equation of a **torus** is used
2. Rotate torus around X and Z axes
3. Apply perspective projection
4. Calculate light reflection (brightness)
5. Choose ASCII character based on brightness
6. Print frame
7. Repeat forever

---

## Why it Looks 3D?

✔ Depth comparison (z-buffer)
✔ Lighting calculation
✔ Continuous rotation

---

> “The donut.c program demonstrates 3D graphics using ASCII characters. It applies trigonometry, rotation, projection, and depth buffering to display a rotating torus in a terminal window.”

---

# 🍩 donut.c — (with comments)

```c
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
```

---

# 📄 README.md for donut.c 

````md
# ASCII Donut in C 🍩

This project demonstrates a rotating **3D donut (torus)** using ASCII characters in the terminal, written in the C programming language.

---

## About the Program

The program uses:
- Trigonometric functions (`sin`, `cos`)
- 3D to 2D projection
- Z-buffer for depth handling
- ASCII shading for lighting
- Infinite loop for animation

It is a classic demonstration of how 3D graphics concepts can be implemented using basic C and mathematics.

---

## Concepts Used

- Trigonometry
- 3D Rotation
- Perspective Projection
- Depth Buffer (Z-buffer)
- ASCII Graphics
- Infinite Loop Animation

---

## How to Compile and Run

### Compile
```bash
gcc donut.c -o donut -lm
````

### Run

```bash
./donut
```

---
