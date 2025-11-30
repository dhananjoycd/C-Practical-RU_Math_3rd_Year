#include <stdio.h>
#include <math.h>

int fact(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}

int main() {
    int n, i, j;
    float x[50], y[50], d[50][50];
    float a, h, u;
    float first_sum, second_sum;
    float first_derivative, second_derivative;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter initial value x: ");
    scanf("%f", &x[0]);

    printf("Enter distance h: ");
    scanf("%f", &h);

    printf("Enter y values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i]);

    // Generate x array
    for (i = 1; i < n; i++)
        x[i] = x[i - 1] + h;

    // Construct forward difference table
    for (i = 0; i < n; i++)
        d[0][i] = y[i];

    for (i = 1; i < n; i++)
        for (j = 0; j < n - i; j++)
            d[i][j] = d[i - 1][j + 1] - d[i - 1][j];

    printf("\nDifference Table:\n");
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++)
            printf("%f\t", d[i][j]);
        printf("\n");
    }

    printf("\nEnter x value where derivative is required: ");
    scanf("%f", &a);

    u = (a - x[0]) / h;

    /********** First Derivative **********/
    first_sum  = d[1][0];
    first_sum += (2*u - 1) * d[2][0] / 2;
    first_sum += (3*u*u - 6*u + 2) * d[3][0] / 6;
    first_sum += (4*u*u*u - 18*u*u + 22*u - 6) * d[4][0] / 24;

    first_derivative = first_sum / h;

    /********** Second Derivative **********/
    second_sum  = d[2][0];
    second_sum += (6*u - 6) * d[3][0] / 6;
    second_sum += (12*u*u - 36*u + 22) * d[4][0] / 24;

    second_derivative = second_sum / (h * h);

    printf("\nFirst derivative f'(%f) = %.6f\n", a, first_derivative);
    printf("Second derivative f''(%f) = %.6f\n", a, second_derivative);

    return 0;
}

/*
Enter number of data points: 5
Enter initial value x: 0
Enter distance h: 1
Enter y values:
0
2
18
84
260

Difference Table:
2.000000        16.000000       66.000000       176.000000
14.000000       50.000000       110.000000
36.000000       60.000000
24.000000

Enter x value where derivative is required: 3

First derivative f'(3.000000) = 109.000000
Second derivative f''(3.000000) = 108.000000

Process returned 0 (0x0)   execution time : 50.126 s
Press any key to continue.
*/

