#include <stdio.h>
#include <math.h>

int main() {
    int i, j, m, n;
    float k;

    printf("Enter the order of the matrix (m n): ");
    scanf("%d%d", &m, &n);

    float A[m][n], C[m][n];

    printf("Enter the scalar value k: ");
    scanf("%f", &k);

    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &A[i][j]);

    // Scalar multiplication: C = k × A
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            C[i][j] = k * A[i][j];

    printf("\n Resultant Matrix (C = k × A):\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%.2f\t", C[i][j]);
        printf("\n");
    }

    return 0;
}

/*
Enter the order of the matrix (m n): 2 2
Enter the scalar value k: 3
Enter elements of Matrix A:
1 2
4 5

Resultant Matrix (C = k * A):
3.00    6.00
12.00   15.00

Process returned 0 (0x0)   execution time : 15.884 s
Press any key to continue.
*/
