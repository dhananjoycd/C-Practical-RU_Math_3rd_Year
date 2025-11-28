#include <stdio.h>
#include <math.h>

// Function to compute p(p+1)(p+2)... / n!
float B(float p, int n)
{
    float num = 1;
    for (int i = 0; i < n; i++)
        num *= (p + i);

    float fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;

    return num / fact;
}

int main()
{
    int n;
    float x0, h, xp, p;
    float y[20][20], xv[20], sum;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter initial x value: ");
    scanf("%f", &x0);

    printf("Enter common difference h: ");
    scanf("%f", &h);

    // Generate x-values
    for (int i = 0; i < n; i++)
        xv[i] = x0 + i * h;

    printf("Enter y values:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &y[i][0]);

    // Build backward difference table (row-wise)
    for (int col = 1; col < n; col++)
    {
        for (int row = n - 1; row >= col; row--)
        {
            y[row][col] = y[row][col - 1] - y[row - 1][col - 1];
        }
    }

    // Print dynamic header
    printf("\nIndex     x        y");
    for (int i = 1; i < n; i++)
        printf("      D%dy", i);
    printf("\n");

    // Print table
    for (int i = 0; i < n; i++)
    {
        printf("%2d   %8.4f ", i, xv[i]);
        for (int j = 0; j <= i; j++)
            printf("%8.4f ", y[i][j]);
        printf("\n");
    }

    // Interpolation
    printf("\nEnter value of x to interpolate: ");
    scanf("%f", &xp);

    p = (xp - xv[n - 1]) / h;  // backward p
    sum = y[n - 1][0];         // last y

    for (int i = 1; i < n; i++)
        sum += B(p, i) * y[n - 1][i];

    printf("\nInterpolated value at x = %.4f is %.4f\n", xp, sum);

    return 0;
}



/*
Enter number of data points: 8
Enter initial x value: 1
Enter common difference h: 1
Enter y values:
1 8 27 64 125 216 343 512

Index     x        y      D1y      D2y      D3y      D4y      D5y      D6y      D7y
 0     1.0000   1.0000
 1     2.0000   8.0000   7.0000
 2     3.0000  27.0000  19.0000  12.0000
 3     4.0000  64.0000  37.0000  18.0000   6.0000
 4     5.0000 125.0000  61.0000  24.0000   6.0000   0.0000
 5     6.0000 216.0000  91.0000  30.0000   6.0000   0.0000   0.0000
 6     7.0000 343.0000 127.0000  36.0000   6.0000   0.0000   0.0000   0.0000
 7     8.0000 512.0000 169.0000  42.0000   6.0000   0.0000   0.0000   0.0000   0.0000

Enter value of x to interpolate: 7.5

Interpolated value at x = 7.5000 is 421.8750

Process returned 0 (0x0)   execution time : 55.940 s
Press any key to continue.

*/
