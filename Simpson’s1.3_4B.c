#include <stdio.h>
#include <math.h>

float f(float x) {

    return sqrt(1-pow(x,2)); //function
}

int main() {
    int i, n;
    float a, b, h, sum_odd = 0, sum_even = 0, result;

    printf("Enter number of sub-intervals (n must be even): ");
    scanf("%d", &n);

    if(n % 2 != 0) {
        printf("Error: n must be even for Simpson 1/3 Rule.\n");
        return 0;
    }

    printf("Enter lower limit a: ");
    scanf("%f", &a);

    printf("Enter upper limit b: ");
    scanf("%f", &b);

    h = (b - a) / n;

    for(i = 1; i < n; i++) {
        float val = f(a + i * h);
        if(i % 2 == 0)
            sum_even += val;
        else
            sum_odd += val;
    }

    result = (h / 3) * (f(a) + f(b) + 4 * sum_odd + 2 * sum_even);

    printf("\n Simpson 1/3 Rule Result = %f\n", result);

    return 0;
}


/*
Enter number of sub-intervals (n must be even): 10
Enter lower limit a: 0
Enter upper limit b: 1

 Simpson 1/3 Rule Result = 0.781752

Process returned 0 (0x0)   execution time : 13.432 s
Press any key to continue.
*/
