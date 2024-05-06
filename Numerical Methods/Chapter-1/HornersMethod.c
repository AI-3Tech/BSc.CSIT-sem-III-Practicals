//C program to implement Horner's Method

#include<stdio.h>
#include<math.h>

int main()
{
    int i, degree, ch;
    float F[10], b1=0, b2, r;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    printf("\nEnter the coefficients of the polynomial");
    for(i=0; i<= degree; i++)
    {
        printf("\nEnter the coefficient of x^%d: ", i);
        scanf("%f", &F[i]);
    }
    Again:
    printf("\nEnter the point at which function is to be evaluated: ");
    scanf("%f", &r);
    for(i=degree; i>=0; i--)
    {
        b2 = F[i] + r * b1;
        b1 = b2;
    }
    printf("\nThe value of polynomial at x = %.2f = %.4f", r, b1);
    printf("\nDo you want to evaluate polynomial at another point(1. Yes 2. No): ");
    scanf("%d", &ch);
    if (ch == 1)
        goto Again;
    return 0;
}