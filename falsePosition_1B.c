#include <stdio.h>
#include <math.h>

float f(float x){
    return pow(x, 3) - 2*x - 5;
}

int main() {
    float a, b, m, tol, h;
    int i = 0, max_iteration = 1000;

    printf("Enter interval [a, b]: ");
    scanf("%f %f", &a, &b);

    // Case: Root present at boundary
    if(f(a) * f(b) == 0){
        if(f(a) == 0 && f(b) == 0)
            printf("Both are roots: a = %.6f, b = %.6f\n", a, b);
        else if(f(a) == 0)
            printf("Root is: %.6f\n", a);
        else
            printf("Root is: %.6f\n", b);

        return 0;
    }

    // Case: No root in interval
    if(f(a) * f(b) > 0){
        printf("No real root in [%f, %f]\n", a, b);
        return 0;
    }

    // Accept tolerance
    printf("Enter tolerance: ");
    scanf("%f", &tol);

    // False Position iterations
    do {
        m = (a * f(b) - b * f(a)) / (f(b) - f(a)); // false position formula
        h = fabs(m - a);  // interval contraction

        if(f(a) * f(m) > 0)
            a = m;
        else
            b = m;

        i++;
        if(i > max_iteration){
            printf("Stopped! Maximum iteration reached.\n");
            break;
        }

    } while(h > tol);

    printf("Approximate Root = %.6f\n", m);
    printf("f(%.6f) = %.6f\n",m,f(m));
    printf("Iterations = %d\n", i);

    return 0;
}
/*
Enter interval [a, b]: 2 3
Enter tolerance: 0.001
Approximate Root = 2.094306
f(2.094306) = -0.002745
Iterations = 6

Process returned 0 (0x0)   execution time : 7.000 s
Press any key to continue.

*/
