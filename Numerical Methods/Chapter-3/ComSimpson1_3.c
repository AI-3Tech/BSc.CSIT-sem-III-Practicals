#include<stdio.h>
#include<math.h>
#define f(x) sqrt(1 - x*x)

int main()
{
    int i, s;
    float x0, xn, fx0, fxn, h, p, term, value;
    printf("Enter the lower and upper limit: ");
    scanf("%f %f", &x0, &xn);
    printf("\nEnter the no. of segments: ");
    scanf("%d", &s);
    h = (xn - x0)/s;
    fx0 = f(x0);
    fxn = f(xn);
    term = fx0 + fxn;
    for(i=1; i<s; i=i+2)
    {
        p = x0 + i*h;
        term = term + 4*(f(p));
    }
    for(i=2; i<s-1; i=i+2)
    {
        p = x0 + i*h;
        term = term + 2*(f(p));
    }
    value = h/3.0 * term;
    printf("\nThe value of the Integration is %.3f", value);
    return 0;
}