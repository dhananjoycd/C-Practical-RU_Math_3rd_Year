#include <stdio.h>
#include <math.h>

float f(float x) {
    return 1.0 / (1.0 + x); //given function
}

int main() {
    int i, n;
    float a, b, h, sum = 0, result;

    printf("Enter number of sub-intervals n: ");
    scanf("%d", &n);

    printf("Enter lower limit a: ");
    scanf("%f", &a);

    printf("Enter upper limit b: ");
    scanf("%f", &b);

    h = (b - a) / n;

    for(i = 1; i < n; i++) {
        sum += f(a + i * h);
    }

    result = (h / 2) * (f(a) + 2 * sum + f(b));

    printf("\nIntegral result using Trapezoidal Rule = %f\n", result);

    return 0;
}

/*
Enter number of sub-intervals n: 100
Enter lower limit a: 0
Enter upper limit b: 1

Integral result using Trapezoidal Rule = 0.693153

Process returned 0 (0x0)   execution time : 31.297 s
Press any key to continue.
*/
