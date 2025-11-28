#include <stdio.h>
#include <math.h>

// Function definition for f(x)
float f(float x) {
    return pow(x, 3) - 3 * x - 5;
}

// Function definition for f'(x)
float df(float x) {
    return 3 * pow(x, 2) - 3;
}

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
        x1 = x - (f(x) / df(x));
        h = fabs(x - x1);
        x = x1;
    } while (h > t);

    printf("The Real Root is %f and f(%f) = %f\n", x, x, f(x));

    return 0;
}
