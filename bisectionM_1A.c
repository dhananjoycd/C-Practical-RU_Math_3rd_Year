#include <stdio.h>
#include <math.h>

float f(float x){
    return (pow(x,3) - x - 1);
}

int main(){
    float a, b, h, t, m;
    int i = 0;

    printf("Enter Interval [a b]: ");
    scanf("%f%f", &a, &b);

    // Check if any endpoint is exactly a root
    if(f(a) * f(b) == 0){
        if(f(a) == 0)
            printf("The root of f(x) is %f\n", a);
        else
            printf("The root of f(x) is %f\n", b);

        return 0;
    }

    // Check sign change
    if(f(a) * f(b) < 0){
        printf("Enter Tolerance: \n");
        scanf("%f", &t);

        do{
            i++;

            m = (a + b) / 2;      // midpoint
            h = fabs(b - a);      // interval length

            if(f(a) * f(m) < 0)
                b = m;
            else
                a = m;

        } while(h > t);

        printf("The root of f(x) is %f\n", m);
        printf("Functional value of f(x) is %f\n",f(m));
        printf("Number of iteration is %d\n",i);
    }
    else{
        printf("The root is not possible in this interval.\n");
    }

    return 0;
}


/*
---Out Put--
Enter Interval [a b]: 1 2
Enter Tolerance:
0.0001
The root of f(x) is 1.324738
Functional value of f(x) is 0.000084
Number of iteration is 15

Process returned 0 (0x0)   execution time : 17.889 s
Press any key to continue.

*/
