#include<stdio.h>
#include<math.h>
#define f(x)  x + 2

int main()
{
    float x0, x1, fx0, fx1, h, value;
    printf("Enter the lower limit: ");
    scanf("%f %f", &x0, &x1);
    h = x1 - x0;
    fx0 = f(x0);
    fx1 = f(x1);
    value = h/2.0 *(fx0 + fx1);
    printf("\nThe integrated value is %.3f ", value);
    return 0;
}