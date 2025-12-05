#include <stdio.h>
#include <math.h>

float f(float x){
    return pow(x, 3) - 2*x - 5;
}

int main(){
    float a,b,h,t,m;
    int i=0;

    printf("Enter Interval [a b]: ");
    scanf("%f%f", &a, &b);

    // Check if any endpoint is exactly a root
    if(f(a) * f(b) == 0){
        if(f(a) == 0 && f(b) == 0)
            printf("Both are root of f(x): a =%f , b =%f \n", a,b);
        else if(f(a) == 0)
            printf("The root of f(x): a  =%f\n", a);
        else
            printf("The root of f(x): b  =%f\n", b);
        return 0;
    }
    else if(f(a) * f(b) < 0){
        printf("Enter Tolerance: \n");
        scanf("%f", &t);

        do{
            i++;
            m = (a*f(b)-b*f(a))/(f(b)-f(a));  // midpoint
            h = fabs(m-a);                  // interval length

            if(f(a) * f(m) < 0)
                b = m;
            else
                a = m;

        } while(h > t);

        printf("The root of f(x) is %f\n", m);
        printf("Functional value of f(x) is %f\n",f(m));
        printf("Number of iteration is %d\n",i);
    }

    else
     printf("The root is not possible in this interval.\n");

    return 0;
}
