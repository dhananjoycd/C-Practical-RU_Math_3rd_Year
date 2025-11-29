#include <stdio.h>
#include <math.h>

float f(float x) {
    return 1.0 / (1.0 + x);
}

int main() {
    int i, n;
    float a, b, h, sum3 = 0, sum2 = 0, result;

    printf("Enter number of sub-intervals  : ");
    scanf("%d", &n);

    if(n % 3 != 0) {
        printf("Error: n must be divisible by 3 for Simpson 3/8 Rule.\n");
        return 0;
    }

    printf("Enter lower limit a: ");
    scanf("%f", &a);

    printf("Enter upper limit b: ");
    scanf("%f", &b);

    h = (b - a) / n;

    for(i = 1; i < n; i++) {
        float val = f(a + i * h);

        if(i % 3 == 0)
            sum2 += val;      // coefficients = 2
        else
            sum3 += val;      // coefficients = 3
    }

    result = (3 * h / 8) * (f(a) + f(b) + 3 * sum3 + 2 * sum2);

    printf("\n Simpson 3/8 Rule Result = %f\n", result);

    return 0;
}


/*
Enter number of sub-intervals  : 9
Enter lower limit a: 0
Enter upper limit b: 1.2

 Simpson 3/8 Rule Result = 0.788478

Process returned 0 (0x0)   execution time : 29.171 s
Press any key to continue.

*/
