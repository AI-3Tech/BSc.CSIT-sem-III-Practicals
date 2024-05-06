//Program to compute first derivative of a function using Background Difference Approximation

#include<stdio.h>
#include<math.h>

float FN(float F[], int degree, float r)
{
    int i;
    float sum = F[0];
    for(i=1; i<= degree; i++)
    {
        sum = sum + F[i] * pow(r, i);
    }
    return sum;
}

int main()
{
    int degree, i, ch;
    float F[10], fdx, fxh, fx, h, x;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    printf("\nEnter the coefficients of the function");
    for(i=0; i<= degree; i++)
    {
        printf("\nCoefficient of x^%d: ", i);
        scanf("%f", &F[i]);
    }
    printf("\nEnter the value at which the derivative is to be calculated: ");
    scanf("%f", &x);
Again:
    printf("\nEnter the value of h: ");
    scanf("%f", &h);
    fxh = FN(F, degree, x-h);
    fx = FN(F, degree, x);
    fdx = (fx - fxh)/h;
    printf("\nThe derivative of the given function at x = %.2f and h = %.2f is %.3f", x, h, fdx);
    printf("\n");
    printf("\nDo you want to calculate the derivative at another value of h (1. Yes 2. No): ");
    scanf("%d", &ch);
    if ( ch == 1)
        goto Again;
    return 0;
}