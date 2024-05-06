//Program to fit exponential regression
#include<stdio.h>
#include<math.h>

int main()
{
    int i, n;
    float a, b, R, X[10], Y[10], LY[10], sx = 0, sy = 0, sx2 = 0, slny = 0, sxlny = 0;
    printf("Enter the no. of data points: ");
    scanf("%d", &n);
    printf("\nEnter the data points and their corresponding functional values, pairwise");
    for(i = 0; i<n; i++)
    {
        printf("\nX%d and Y%d: ", i, i);
        scanf("%f %f", &X[i], &Y[i]);
    }
    for(i = 0; i<n; i++)
    {
        LY[i] = log(Y[i]);
    }
    for(i =0; i<n; i++)
    {
        sx = sx + X[i];
        slny = slny + LY[i];
        sx2 = sx2 + X[i]*X[i];
        sxlny = sxlny + X[i]*LY[i];
    }
    b = (n*sxlny - sx*slny)/(n*sx2 - sx*sx);
    R = slny/(float)n - b*sx/(float)n;
    a = exp(R);
    printf("\nb = %.3f \t R = %.3f \t a = %.3f", b, R, a);
    printf("\nThe power function is \t Y = %.3fe^(%.3fx)", a, b);
    return 0;
}