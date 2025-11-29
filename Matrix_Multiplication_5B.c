#include <stdio.h>
#include <math.h>

int main() {
    int i, j, k, m1, n1, m2, n2;

    printf("Enter size of Matrix A (m n): ");
    scanf("%d%d", &m1, &n1);

    printf("Enter size of Matrix B (m n): ");
    scanf("%d%d", &m2, &n2);

    // Condition for multiplication: n1 must equal m2
    if (n1 != m2) {
        printf("Matrix multiplication NOT possible.\n");
        return 0;
    }
        // Matrix declare
    float A[m1][n1], B[m2][n2], C[m1][n2];

    printf("\nEnter elements of Matrix A:\n");
    for (i = 0; i < m1; i++)
        for (j = 0; j < n1; j++)
            scanf("%f", &A[i][j]);

    printf("\nEnter elements of Matrix B:\n");
    for (i = 0; i < m2; i++)
        for (j = 0; j < n2; j++)
            scanf("%f", &B[i][j]);

    // Initialize C to zero
    for (i = 0; i < m1; i++)
        for (j = 0; j < n2; j++)
            C[i][j] = 0;

    // Matrix Multiplication: C = A × B
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            for (k = 0; k < n1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResultant Matrix (C = A × B):\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++)
            printf("%.2f\t", C[i][j]);
        printf("\n");
    }

    return 0;
}


/*
Enter size of Matrix A (m n): 3 2
Enter size of Matrix B (m n): 2 3

Enter elements of Matrix A:
1 1
2 2
3 3

Enter elements of Matrix B:
1 1 1
2 2 2

Resultant Matrix (C = A * B):
3.00    3.00    3.00
6.00    6.00    6.00
9.00    9.00    9.00

Process returned 0 (0x0)   execution time : 30.626 s
Press any key to continue.

*/
