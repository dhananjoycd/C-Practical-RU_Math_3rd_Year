# C program - Math 3rd Year

## 1(a) - The problem we are solving is known as the **"Bisection Method for Finding Roots"**.

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
