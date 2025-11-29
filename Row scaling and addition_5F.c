#include <stdio.h>
#include <math.h>

int main()
{
    float a[5][5], k;
    int m, n, m1, n1, i, j;

    printf("Enter order of matrix A:\n");
    scanf("%d%d", &m, &n);

    printf("Enter elements A:\n");
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);

    printf("Enter row to scale (m1) and scaling value k:\n");
    scanf("%d%f", &m1, &k);

    printf("Enter row to add (n1):\n");
    scanf("%d", &n1);

    for (j = 1; j <= n; j++)
        a[m1][j] = k * a[m1][j] + a[n1][j];

    printf("Matrix after scaling:\n");
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%.1f\t", a[i][j]);
        printf("\n");
    }
}

/*
Enter order of matrix A:
3 3
Enter elements A:
1 2 3
4 5 6
7 8 9
Enter row to scale (m1) and scaling value k:
3 2
Enter row to add (n1):
1
Matrix after scaling:
1.0     2.0     3.0
4.0     5.0     6.0
15.0    18.0    21.0

Process returned 0 (0x0)   execution time : 26.401 s
Press any key to continue.

*/
