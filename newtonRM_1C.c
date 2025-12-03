#include <stdio.h>
#include <math.h>

// Function definition for f(x)
float f(float x)
{
    return (sin(x) - x / 2);
}

// Function definition for f'(x)
float df(float x)
{
    return cos(x) - 0.5;
}

int main()
{
    float x, x1, h, t;

    printf("Enter the initial point: ");
    scanf("%f", &x);

    if (df(x) == 0)
    {
        printf("The given point is not suitable.\n");
        return 0;
    }

    printf("Enter the tolerance: ");
    scanf("%f", &t);

    do
    {
        x1 = x - (f(x) / df(x));
        h = fabs(x - x1);
        x = x1;
    } while (h > t);

    printf("The Real Root is %f and f(%f) = %f\n", x, x, f(x));

    return 0;
}

/*
Enter the initial point: 1.5708
Enter the tolerance: .0001
The Real Root is 1.895494 and f(1.895494) = 0.000000

Process returned 0 (0x0)   execution time : 28.031 s
Press any key to continue.

*/
