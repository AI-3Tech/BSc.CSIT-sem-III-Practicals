#include<stdio.h>
#include<math.h>
#define f(x,y)  (x*x+y*y)

int main()
{
    float x, x0, y0, xn, y, h, m1, m2, m3, m4;
    printf("Enter initial values: ");
    scanf("%f %f", &x0, &y0);
    printf("\nEnter value at which function is to be evaluated: ");
    scanf("%f", &xn);
    printf("\nEnter the step size: ");
    scanf("%f", &h);
    y = y0;
    for(x = x0; x<xn; x = x+h)
    {
        m1 =f(x, y);
        m2 =f((x+1/2.0 *h), (y+1/2.0*h*m1));
        m3 =f((x+1/2.0*h),(y+1/2.0*h*m2));
        m4 =f((x+h),(y+h*m3));
        y =y + h/6.0 *(m1+2*m2+2*m3+m4);
    }
    printf("\nThe functional value at x = %.3f is %f", xn, y);
    return 0;
}