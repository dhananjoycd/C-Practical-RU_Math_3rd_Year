#include <stdio.h>
#include <math.h>

int main(){
int i,j,n;
float x[100],y[100],xp,p, yp=0;

   printf("Enter number of data points: ");
    scanf("%d", &n);

      printf("Enter x values:\n");
      for(i=0; i<n; i++)
        scanf("%f", &x[i]);

      printf("Enter y values:\n");
      for(i=0; i<n; i++)
        scanf("%f", &y[i]);

    printf("Enter the value of x for interpolation: ");
    scanf("%f", &xp);

    for(i=0; i<n; i++){
        p=1;
        for(j=0; j<n; j++){
            if(i!=j)
                p*=(xp-x[j])/(x[i]-x[j]);
        }
        yp+=p*y[i];
    }
printf("\n Interpolated value at x = %.4f is y = %.4f\n", xp, yp);

    return 0;
}
