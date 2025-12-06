#include <stdio.h>
#include <math.h>

float B(float p, int n){
    float num=1, fact=1;
    for (int i=0; i<n; i++){
        num*= p+i;
        fact*= i+1;
    }
    return num/fact;
}

int main(){
int n;
float x,h,y[20][20],xp,xv[20],p,sum;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter initial x value: ");
    scanf("%f", &x);

    printf("Enter common difference h: ");
    scanf("%f", &h);

    printf("Enter y values:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &y[i][0]);

    printf("Enter value of x to interpolate: ");
    scanf("%f", &xp);

    //generate x values
    for(int i=0; i<n; i++)
        xv[i]=x+i*h;

        //backward difference table (row-wise)
    for(int col=1; col<n; col++){
        for(int row=n-1; row>=col; row--)
            y[row][col] = y[row][col-1]-y[row-1][col-1];
    }


    //Print dynamic header
    printf("\nIndex     x      y");
    for (int i = 1; i < n; i++)
        printf("      D%dy", i);
    printf("\n");

    // Print table
    for (int i = 0; i < n; i++)
    {
        printf("%2d   %8.4f ", i, xv[i]);
        for (int j = 0; j <= i; j++)
            printf("%8.4f ", y[i][j]);
        printf("\n");
    }

    // Interpolation
    p = (xp - xv[n - 1]) / h;  // backward p
    sum = y[n - 1][0];         // last y

    for(int i=1; i<n; i++)
        sum+=B(p,i)*y[n-1][i];


    printf("\nInterpolated value at x = %.4f is %.4f\n", xp, sum);

    return 0;
}
