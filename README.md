# C program - Math 3rd Year

## Program 1(a): Find a root by bisection section method

```c
#include <stdio.h>
#include <math.h>

// Function declaration before usage
float f(float x);

int main() {
    float a, b, x, h, t;

    printf("Enter the values for a and b: ");
    scanf("%f %f", &a, &b);

    if (f(a) * f(b) == 0) {
        if (f(a) == 0)
            printf("Root is %f\n", a);
        else
            printf("Root is %f\n", b);
    } else if (f(a) * f(b) > 0) {
        printf("The given points are not suitable.\n");
    } else {
        printf("Enter the tolerance: ");
        scanf("%f", &t);

        // Bisection Method logic
        do {
            x = (a + b) / 2.0;
            if (f(x) * f(a) > 0) {
                a = x;
            } else {
                b = x;
            }
            h = fabs(a - b);
        } while (h > t);

        printf("Root is %f and f(%f) = %f\n", x, x, f(x));
    }

    return 0;
}

float f(float x) {
    return pow(x, 3) - 2 * x - 5;
}

```

## Program 1(c): Find a root by Newton-Raphsonmethod.

```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // For exit()

// Function declarations
float f(float x);
float df(float x);

int main() {
    float x, x1, h, t;

    printf("Enter the initial point: ");
    scanf("%f", &x);

    if (df(x) == 0) {
        printf("The given point is not suitable.\n");
        exit(0);
    }

    printf("Enter the tolerance: ");
    scanf("%f", &t);

    do {
        x1 = x - f(x) / df(x);
        h = fabs(x - x1);
        x = x1;
    } while (h > t);

    printf("Root is %f and f(%f) = %f\n", x, x, f(x));

    return 0;
}

// Function definition for f(x)
float f(float x) {
    return pow(x, 3) - 2 * x - 5;
}

// Function definition for f'(x)
float df(float x) {
    return 3 * pow(x, 2) - 2;
}

```
