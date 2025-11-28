#include<stdio.h>
#include<math.h>
 int main()
 {
    float a,b,tol,m,h;
    int i=0;
    float f(float);
    printf("enter the interval [a,b] \n");
    scanf("%f%f",&a,&b);
    if(f(a)*f(b)==0){
        if(f(a)==0)
            printf("%f is a root of f(x)\n",a);
        else
            printf("%f is a root of f(x)\n",b);
    }
    else if(f(a)*f(b)<0){
     printf("Enter the tolerance \n");
     scanf("%f",&tol);
     while(1){
             i++;
  h=fabs(a-b);
  m=(a+b)/2;
  if(f(a)*f(m)<0) b=m;
  else a=m;
  if(h<tol) break;
     }
     printf("%f is an approximate root of f(x)\n",m);
     printf("Functional value of f(x)at %f is %f\n",m,f(m));
     printf("Number of iteration is %d\n",i);
    }
    else printf("f may not have a root in the interval");
    return 0;
 }
 float f(float x)
 {
    return (pow(x,3)-x-1);
 }


 // This program can find a root of given equation by bisection method.
    // Given equation is : x3-x-1=0



