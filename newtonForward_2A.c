#include <stdio.h>
#include <math.h>

// Function to compute p(p-1)(p-2).../n!
float F(float p, int n){

    float num = 1, fact = 1;
    for (int i = 0; i < n; i++){
    num *= (p - i);
    fact *= i+1;
}
    return num / fact;
}

int main()
{
    int n;
    float x, h, xp, p;
    float y[20], d[20][20], sum;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter initial x value: ");
    scanf("%f", &x);

    printf("Enter common difference h: ");
    scanf("%f", &h);

    printf("Enter y values:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &y[i]);

    printf("Enter value of x to interpolate: ");
    scanf("%f", &xp);

    // Place y values into d[0]
    for (int i = 0; i < n; i++)
        d[i][0] = y[i];

    // Build row-wise difference table
    for (int col = 1; col < n; col++)
    {
        for (int row = 0; row < n - col; row++)
        {
            d[row][col] = d[row + 1][col - 1] - d[row][col - 1];
        }
    }

    // Print header dynamically
    printf("Index     y");
    for (int i = 1; i < n; i++)
        printf("      D%dy", i);
    printf("\n");

    // Print table rows
    for (int i = 0; i < n; i++)
    {
        printf("%2d   ", i); // index printing
        for (int j = 0; j < n - i; j++)
            printf("%8.4f ", d[i][j]);  //print y
        printf("\n");
    }

    // Newton forward interpolation
    p = (xp - x) / h;
    sum = d[0][0];

    for (int i = 1; i < n; i++)
        sum += F(p, i) * d[0][i];

    printf("\n Interpolated value at x = %.4f is %.4f\n", xp, sum);
    return 0;
}

/* Enter number of data points: 6
Enter initial x value: 2.5
Enter common difference h: .5
Enter y values:
24.145
22.043
20.225
18.644
17.262
16.047
Enter value of x to interpolate: 3.75

Row-wise Difference Table:
Index     y      D1y      D2y      D3y      D4y      D5y
 0    24.1450  -2.1020   0.2840  -0.0470   0.0090  -0.0030
 1    22.0430  -1.8180   0.2370  -0.0380   0.0060
 2    20.2250  -1.5810   0.1990  -0.0320
 3    18.6440  -1.3820   0.1670
 4    17.2620  -1.2150
 5    16.0470

 Interpolated value at x = 3.7500 is 19.4074

Process returned 0 (0x)   execution time : 25.456 s
Press any key to continue.
*/
