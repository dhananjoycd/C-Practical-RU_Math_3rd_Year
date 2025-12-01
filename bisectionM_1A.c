#include<stdio.h>
#include<math.h>

 float f(float x)
 {
    return (pow(x,3)-x-1);
 }

 int main()
 {
    float a,b,tol,m,h;
    int i=0;
    printf("Enter the interval [a,b]: ");
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

 /* This program can find a root of given equation by bisection method.
    // Given equation is : x3-x-1=0

----------out put---------
Enter the interval [a,b]: 1 2

Enter the tolerance
0.0001
1.324738 is an approximate root of f(x)
Functional value of f(x)at 1.324738 is 0.000084
Number of iteration is 15

Process returned 0 (0x0)   execution time : 11.111 s
Press any key to continue.
-----------------------------------
*/


/*Solve hints:

-Sub function build
-Main Function build:
        .variable declaration
        .check the root by using "if"
         => f(a)*f(b)=0 then we can find root 'a' or 'b'
         => f(a)*f(b)<0 then need tolerance and use "while loop"
         Here, m =(a+b)/2 => f(a)*f(m)<0 b=m else a=m
         Now check, h=fabs(a-b)<tolerance to stop the loop
-Print OutPut

*/
