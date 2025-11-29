#include <stdio.h>
#include <math.h>

int main() {
    float a[10][10], temp;
    int m, n, r1, r2, i, j;

    printf("Enter the order of matrix A (m n): ");
    scanf("%d%d", &m, &n);

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &a[i][j]);

    printf("Enter two rows to interchange (1-based): ");
    scanf("%d%d", &r1, &r2);

    r1--;  //convert to 0-based
    r2--;

    for (j = 0; j < n; j++) {   // swap full rows
        temp = a[r1][j];
        a[r1][j] = a[r2][j];
        a[r2][j] = temp;
    }

    printf("\nMatrix after row interchange:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%.1f\t", a[i][j]);
        printf("\n");
    }

    return 0;
}
/*
Enter the order of matrix A (m n): 3 3
Enter the elements of matrix A:
1 2 3
4 5 6
7 8 9
Enter two rows to interchange (1-based): 2 3

Matrix after row interchange:
1.0     2.0     3.0
7.0     8.0     9.0
4.0     5.0     6.0

Process returned 0 (0x0)   execution time : 28.701 s
Press any key to continue.
*/
