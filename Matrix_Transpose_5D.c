#include <stdio.h>
#include <math.h>

int main() {
    int i, j, m, n;

    printf("Enter the order of the matrix (m n): ");
    scanf("%d%d", &m, &n);

    float A[m][n], T[n][m];

    printf("Enter the elements of Matrix A:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &A[i][j]);

    // Transpose: T[j][i] = A[i][j]
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            T[j][i] = A[i][j];

    printf("\nTranspose Matrix (A^T):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%.2f\t", T[i][j]);
        printf("\n");
    }

    return 0;
}
/*
Enter the order of the matrix (m n): 3 3
Enter the elements of Matrix A:
1 2 3
4 5 6
7 8 9

Transpose Matrix (A^T):
1.00    4.00    7.00
2.00    5.00    8.00
3.00    6.00    9.00

Process returned 0 (0x0)   execution time : 821.308 s
Press any key to continue.
*/
