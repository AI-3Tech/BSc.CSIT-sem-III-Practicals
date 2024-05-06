#include<stdio.h>
#include<math.h>
#define f(x)  3*x*x + 2*x - 5

int main()
{
    int i, s;
    float x0, xn, fx0, fxn, h, p, term, value;
    printf("Enter the lower limit and upper limit: ");
    scanf("%f %f", &x0, &xn);
    printf("\nEnter the no. of segments: ");
    scanf("%d", &s);
    h = (xn - x0)/s;
    fx0 = f(x0);
    fxn = f(xn);
    term = fx0 + fxn;
    for(i=1; i<s; i++)
    {
        p = x0 + i*h;
        term = term + 2*(f(p));
    }
    value = h/2.0 *term;
    printf("\nThe integrated value is %.3f ", value);
    return 0;
}