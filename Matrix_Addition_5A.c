#include <stdio.h>
#include <math.h>

int main() {
    int i, j, m1, n1, m2, n2;

    printf("Enter the size of Matrix A (m n): ");
    scanf("%d%d", &m1, &n1);

    printf("Enter the size of Matrix B (m n): ");
    scanf("%d%d", &m2, &n2);

    if (m1 != m2 || n1 != n2) {
        printf("Matrix addition NOT possible. Orders must match.\n");
        return 0;
    }
        //dynamic index of matrix
    float a[m1][n1], b[m2][n2], c[m1][n1];

    printf("Enter the elements of Matrix A:\n");
    for (i = 0; i < m1; i++)
        for (j = 0; j < n1; j++)
            scanf("%f", &a[i][j]);

    printf("Enter the elements of Matrix B:\n");
    for (i = 0; i < m2; i++)
        for (j = 0; j < n2; j++)
            scanf("%f", &b[i][j]);

    // Matrix Addition
    for (i = 0; i < m1; i++)
        for (j = 0; j < n1; j++)
            c[i][j] = a[i][j] + b[i][j];

    printf("\nMatrix Addition (C = A + B):\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++)
            printf("%.2f\t", c[i][j]);
        printf("\n");
    }

    return 0;
}


/*
Enter the size of Matrix A (m n): 3 3
Enter the size of Matrix B (m n): 3 3
Enter the elements of Matrix A:
3 4 5
7 6 4
2 4 9
Enter the elements of Matrix B:
5 3 7
4 3 6
2 6 9

Matrix Addition (C = A + B):
8.00    7.00    12.00
11.00   9.00    10.00
4.00    10.00   18.00

Process returned 0 (0x0)   execution time : 46.731 s
Press any key to continue.

*/
