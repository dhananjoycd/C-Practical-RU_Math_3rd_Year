#include <stdio.h>
#include <math.h>

// Original equation: x^3 + x^2 - 1 = 0
float f(float x)
{
    return (pow(x, 3) + pow(x, 2) - 1);
}

// Iteration function g(x) = 1 / sqrt(x + 1)
float g(float x)
{
    return (1.0 / sqrt(x + 1));
}

// g'(x)
float gprime(float x)
{
    return (-0.5 * pow(x + 1, -1.5));
}

int main()
{
    float x, x1, tol, h;
    int i = 0;

    printf("Enter initial guess x = ");
    scanf("%f", &x);

    // Check convergence condition |g'(x)| < 1
    if (fabs(gprime(x)) >= 1)
    {
        printf("The given initial guess is NOT suitable.\n");
        return 0;
    }

    printf("Enter tolerance: ");
    scanf("%f", &tol);

    printf("\n Iteration results:\n");
    printf("Iteration \t   x\n");

    do
    {
        i++;
        x1 = g(x);
        h = fabs(x1 - x);
        printf("%d\t%f\n", i, x1);
        x = x1;
    } while (h > tol);

    printf("\n Approximate root = %f \n", x1);
    printf("The functional value f(%f) = %f\n", x1, f(x1));
    printf("Total iterations = %d\n",i);

    return 0;
}

/*
Enter initial guess x =
0.5
Enter tolerance: 0.0001

 Iteration results:
Iteration          x
1       0.816497
2       0.741964
3       0.757671
4       0.754278
5       0.755007
6       0.754850
7       0.754884

 Approximate root = 0.754884
The functional value f(0.754884) = 0.000019
Total iterations = 7

Process returned 0 (0x0)   execution time : 33.668 s
Press any key to continue.
*/
