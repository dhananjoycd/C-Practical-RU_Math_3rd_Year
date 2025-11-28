#include <stdio.h>
#include <math.h>

float fact(int n) {
    float f = 1;
    for(int i=1; i<=n; i++) f *= i;
    return f;
}

int main() {
    int n, i, j;
    float x[50], y[50], d[50][50];
    float a, h, u, sum = 0, derivative;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter the initial value x: ");
    scanf("%f", &x[0]);

    printf("Enter distance between x values h: ");
    scanf("%f", &h);

    printf("Enter y values:\n");
    for(i=0; i<n; i++)
        scanf("%f", &y[i]);

    // Generate x array
    for(i=1; i<n; i++)
        x[i] = x[i-1] + h;

    // Difference table
    for(i=0; i<n; i++)
        d[0][i] = y[i];

    for(i=1; i<n; i++)
        for(j=0; j<n-i; j++)
            d[i][j] = d[i-1][j+1] - d[i-1][j];

    printf("\nDifference Table:\n");
    for(i=1; i<n; i++) {
        for(j=0; j<n-i; j++)
            printf("%f\t", d[i][j]);
        printf("\n");
    }

    printf("\nEnter x value where derivative is required: ");
    scanf("%f", &a);

    u = (a - x[0]) / h;

    // Apply Newton forward derivative formula
    sum  = d[1][0];
    sum += (2*u - 1) * d[2][0] / 2;
    sum += (3*u*u - 6*u + 2) * d[3][0] / 6;
    sum += (4*u*u*u - 18*u*u + 22*u - 6) * d[4][0] / 24;

    derivative = sum / h;

    printf("\nFirst derivative at x = %.4f is %.4f\n", a, derivative);

    return 0;
}


/*
Enter number of data points: 5
Enter the initial value x: 0
Enter distance between x values h: 1
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

First derivative at x = 3.0000 is 109.0000

Process returned 0 (0x0)   execution time : 21.072 s
Press any key to continue.
*/
