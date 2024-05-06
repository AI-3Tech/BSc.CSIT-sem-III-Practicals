#include<stdio.h>
#include<math.h>
#define f(x)  x*x*x + 1

int main()
{
    int n=3;
    float x0, x1, x2, x3, fx0, fx1, fx2, fx3, h, value;
    printf("Enter the lower and upper limit: ");
    scanf("%f %f", &x0, &x3);
    h = (x3 - x0)/n;
    x1 = x0 + h;
    x2 = x0 + 2*h;
    fx0 = f(x0);
    fx1 = f(x1);
    fx2 = f(x2);
    fx3 = f(x3);
    value = h*3/8.0 * (fx0 + 3*fx1 + 3*fx2 + fx3);
    printf("\nThe value of the Integration is %.3f", value);
    return 0;
}