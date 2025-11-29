#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, iter;
    // Arrays for up to 10 variables
    float a[10][10], b[10], x[10], x_old[10], sum;

    // --- Input Section ---
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

    // Initial guess: x = 0
    for (i = 0; i < n; i++)
        x[i] = 0;

    // --- Iteration Section (The Core Logic) ---
    printf("\nIteration table:\n");
    for (int k = 1; k <= iter; k++) {

        // 1. Save the previous solution set before calculating the new one
        for (i = 0; i < n; i++)
            x_old[i] = x[i];

        // 2. Apply the Gauss-Seidel formula for each variable
        for (i = 0; i < n; i++) {
            sum = 0;

            // Calculate the sum of terms (excluding the diagonal a[i][i]*x[i])
            for (j = 0; j < n; j++) {
                if (i != j) {
                    // Gauss-Seidel uses the NEWEST values available:
                    if (j < i)
                        sum += a[i][j] * x[j];      // Use updated x[j]
                    else
                        sum += a[i][j] * x_old[j];  // Use value from previous iteration
                }
            }

            // Update the current variable: x_i = (b_i - sum) / a_ii
            x[i] = (b[i] - sum) / a[i][i];
        }

        // 3. Print current iteration result
        printf("Iteration %d: ", k);
        for (i = 0; i < n; i++)
            printf("%10.4f ", x[i]);
        printf("\n");
    }

    // --- Output Section ---
    printf("\nApproximate solution:\n");
    for (i = 0; i < n; i++)
        printf("x_%d = %10.4f\n", i + 1, x[i]);

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
Enter the number of iterations: 4

Iteration table:
Iteration 1:     3.1481     3.5407     1.9132
Iteration 2:     2.4322     3.5720     1.9258
Iteration 3:     2.4257     3.5729     1.9260
Iteration 4:     2.4255     3.5730     1.9260

Approximate solution:
x_1 =     2.4255
x_2 =     3.5730
x_3 =     1.9260

Process returned 0 (0x0)   execution time : 29.030 s
Press any key to continue.
*/
