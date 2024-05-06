#include<stdio.h>
#include<math.h>
#define f(x,y)  (x*x+y*y)

int main()
{
    float x, x0, y0, xn, y, h;
    printf("Enter initial values: ");
    scanf("%f %f", &x0, &y0);
    printf("\nEnter value at which function is to be evaluated: ");
    scanf("%f", &x);
    printf("\nEnter the step size: ");
    scanf("%f", &h);
    y = y0;
    for(xn = x0; xn<x; xn = xn+h)
    {
        y = y + f(xn,y) * h;
    }
    printf("\nThe functional value at x = %.3f is %f", x, y);
    return 0;
}


