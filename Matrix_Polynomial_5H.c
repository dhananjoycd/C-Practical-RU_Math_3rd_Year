#include <stdio.h>
#include <math.h>

int main() {
    int i, j, k, n;
    float A[5][5], A2[5][5], A3[5][5], I[5][5], F[5][5];

    printf("Enter order of Square matrix A: ");
    scanf("%d", &n);

    printf("Enter elements of matrix A:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%f", &A[i][j]);

    // Create identity matrix automatically
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            I[i][j] = (i == j) ? 1 : 0;


    //-----Build Matrix polynomial----

    // Compute A^2
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++) {
            A2[i][j] = 0;
            for(k = 1; k <= n; k++)
                A2[i][j] += A[i][k] * A[k][j];
        }

    // Compute A^3
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++) {
            A3[i][j] = 0;
            for(k = 1; k <= n; k++)
                A3[i][j] += A2[i][k] * A[k][j];
        }

    // -------- Write polynomial Equation --------

    // F(A) = A^3 - 5A^2 + 7A - 3I
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            F[i][j] = A3[i][j] - 5*A2[i][j] + 7*A[i][j] - 3*I[i][j];


    printf("\n Result of matrix polynomial F(A):\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            printf("%.2f\t", F[i][j]);
        printf("\n");
    }

    return 0;
}

/*
Enter order of Square matrix A: 2
Enter elements of matrix A:
1 2
3 4

 Result of matrix polynomial F(A):
6.00    18.00
27.00   33.00

Process returned 0 (0x0)   execution time : 14.390 s
Press any key to continue.

*/
