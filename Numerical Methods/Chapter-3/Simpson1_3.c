#include<stdio.h>
#include<math.h>
#define f(x)  3*x*x + 2*x -5

int main()
{
    int n=2;
    float x0, x1, x2, fx0, fx1, fx2, h, value;
    printf("Enter the lower and upper limit: ");
    scanf("%f %f", &x0, &x2);
    h = (x2 - x0)/n;
    x1 = x0 + h;
    fx0 = f(x0);
    fx1 = f(x1);
    fx2 = f(x2);
    value = h/3.0 * (fx0 + 4*fx1 + fx2);
    printf("\nThe value of the Integration is %.3f", value);
    return 0;
}