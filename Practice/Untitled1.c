#include <stdio.h>
#include <math.h>

float F(float p, int n){
    float num=1, fact=1;
    for(int i =0; i<n; i++){
        num*=p-i;
        fact*=i+1;
    }
    return num/fact;
}

int main(){
int n;
float x,h,y[20][20],xp,p,sum;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter initial x value: ");
    scanf("%f", &x);

    printf("Enter common difference h: ");
    scanf("%f", &h);

     printf("Enter y values:\n");
     for(int i=0; i<n; i++)
        scanf("%f", &y[i][0]);

    printf("Enter value of x to interpolate: ");
    scanf("%f", &xp);

    for (int col=1; col<n; col++){
        for(int row=0; row<n-col; row++)
            y[row][col] = y[row+1][col-1]-y[row][col-1];
    }


       //header
  printf("Index     y");
     for (int i = 1; i < n; i++)
        printf("\t   D%dy",i);
        printf("\n");

    //body
     for (int i = 0; i < n; i++){
      printf("%2d   ", i); // index printing
        for(int j=0; j<n-i; j++ )
         printf("%8.4f", y[i][j]);
         printf("\n");
     }

    // Newton forward interpolation
     p =(xp-x)/h;
     sum=y[0][0];

    for (int i = 1; i < n; i++)
        sum+=F(p,i)*y[0][i];

    printf("\n Interpolated value at x = %.4f is %.4f\n", xp, sum);
    return 0;

}
