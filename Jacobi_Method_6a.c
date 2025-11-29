#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, iter;
    float a[10][10], b[10], x[10], x_old[10], sum;

    printf("Enter the number of variables (order of system): ");
    scanf("%d", &n);

    printf("Enter the coefficient matrix A (%dx%d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &a[i][j]);

    printf("Enter the constants vector b:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &b[i]);

    printf("Enter the number of iterations: ");
    scanf("%d", &iter);

    // Initial guess x = 0
    for (i = 0; i < n; i++)
        x[i] = 0;

    printf("\nIteration table:\n");
    for (int k = 1; k <= iter; k++) {
        // Copy previous iteration
        for (i = 0; i < n; i++)
            x_old[i] = x[i];

        // Jacobi formula
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = 0; j < n; j++) {
                if (i != j)
                    sum += a[i][j] * x_old[j];
            }
            x[i] = (b[i] - sum) / a[i][i];
        }

        // Print current iteration
        printf("Iteration %d: ", k);
        for (i = 0; i < n; i++)
            printf("%8.4f ", x[i]);
        printf("\n");
    }

    // Final approximate solution
    printf("\nApproximate solution:\n");
    for (i = 0; i < n; i++)
        printf("x_%d = %8.4f\n", i + 1, x[i]);

    return 0;
}

/*
Enter the number of variables (order of system): 3
Enter the coefficient matrix A (3x3):
27 6 -1
6 15 2
1 1 54
Enter the constants vector b:
85 72 110
Enter the number of iterations: 7

Iteration table:
Iteration 1:   3.1481   4.8000   2.0370
Iteration 2:   2.1569   3.2691   1.8898
Iteration 3:   2.4917   3.6852   1.9366
Iteration 4:   2.4009   3.5451   1.9226
Iteration 5:   2.4316   3.5833   1.9269
Iteration 6:   2.4232   3.5705   1.9257
Iteration 7:   2.4260   3.5740   1.9260

Approximate solution:
x_1 =   2.4260
x_2 =   3.5740
x_3 =   1.9260

Process returned 0 (0x0)   execution time : 58.071 s
Press any key to continue.
*/
