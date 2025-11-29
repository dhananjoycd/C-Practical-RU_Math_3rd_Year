#include <stdio.h>
#include <math.h>

int main() {
    float a[10][10], s[10][10], sk[10][10];
    int i, j, n;

    printf("Enter the order of Square matrix A: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &a[i][j]);

    // Symmetric matrix S = (A + A')/2
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            s[i][j] = (a[i][j] + a[j][i]) * 0.5;

    printf("\nSymmetric Matrix S:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%.2f\t", s[i][j]);
        printf("\n");
    }

    // Skew-Symmetric matrix K = (A - A')/2
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            sk[i][j] = (a[i][j] - a[j][i]) * 0.5;

    printf("\nSkew-Symmetric Matrix K:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%.2f\t", sk[i][j]);
        printf("\n");
    }

    // Optional: Verify S + K = A
    printf("\n The sum of S and K =:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%.2f\t", s[i][j] + sk[i][j]);
        printf("\n");
    }

    return 0;
}
/*
Enter the order of Square matrix A: 3
Enter the elements of matrix A:
4 2 -1
3 1 5
0 -2 6

Symmetric Matrix S:
4.00    2.50    -0.50
2.50    1.00    1.50
-0.50   1.50    6.00

Skew-Symmetric Matrix K:
0.00    -0.50   -0.50
0.50    0.00    3.50
0.50    -3.50   0.00

The sum of S and K =:
4.00    2.00    -1.00
3.00    1.00    5.00
0.00    -2.00   6.00

Process returned 0 (0x0)   execution time : 37.324 s
Press any key to continue.

*/

