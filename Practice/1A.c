#include <stdio.h>
#include <math.h>

float f(float x){
return (cos(x)-x*exp(x));
}

float g(float x){
return(cos(x)*exp(-x));
}

float gp(float x){
return(-exp(-x)*(sin(x)+cos(x)));
}


int main(){
float x,x1,h,t;
int i=0;

printf("Initial guess: ");
scanf("%f",&x);

if(fabs(gp(x)>=1)){
    printf("Root doesn't exit");
    return 0;
}

printf("Enter tolarence: ");
scanf("%f",&t);

printf("Iteration Result: \n");
printf("Iteration \t x\n");

do{
    i++;
    x1=g(x);
    h=fabs(x-x1);
    printf("%d \t \t%f \n", i, x1);
    x=x1;
}while(h>t);

printf("total iteration: %d \n", i);
printf("Iteration result: %f \n", x1);
printf("Functional Value f(%f) = %f \n", x1, f(x1));

return 0;
}
