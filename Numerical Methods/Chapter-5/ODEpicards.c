#include<stdio.h>
#include<math.h>
#define y1(x) x + pow(x, 2)/2
#define y2(x) y1(x)+pow(x, 3)/3 + pow(x,4)/8
#define y3(x) y2(x)+pow(x,5)/15 + pow(x,6)/48

int main()
{
    float x, x0, y0, y, yn, E;
    printf("Enter initial values: ");
    scanf("%f %f", &x0, &y0);
    printf("\nEnter value at which function is to be evaluated: ");
    scanf("%f", &x);
    y = y0;
    y = y0 + y1(x);
    y = y0 + y2(x);
    y = y0 + y3(x);
    printf("\nThe functional value at x = %.3f is %f", x, y);
    return 0;
}


