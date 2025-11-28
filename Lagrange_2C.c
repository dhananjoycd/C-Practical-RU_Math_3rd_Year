#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j;
    float x[100], y[100], xp;
    float yp = 0, p;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &y[i]);

    printf("Enter the value of x for interpolation: ");
    scanf("%f", &xp);

    // Lagrange Interpolation Formula
    for(i = 0; i < n; i++){
        p = 1;
        for(j = 0; j < n; j++){
            if(j != i)
                p = p * ( (xp - x[j]) / (x[i] - x[j]) );
        }
        yp = yp + p * y[i];
    }

    printf("\n Interpolated value at x = %.4f is y = %.4f\n", xp, yp);

    return 0;
}

/*
Enter number of data points: 4
Enter x values:
5
6
9
11
Enter y values:
12
13
14
16
Enter the value of x for interpolation: 10

Interpolated value at x = 10.0000 is y = 14.6667

Process returned 0 (0x0)   execution time : 48.994 s
Press any key to continue.

*/
