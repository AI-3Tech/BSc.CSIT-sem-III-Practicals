//C program to implement Synthetic Division Method

#include<stdio.h>
#include<math.h>

int main()
{
    int i, degree, ch;
    float F[10], B[10],b1=0, b2, r;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    printf("\nEnter the coefficients of the polynomial");
    for(i=0; i<= degree; i++)
    {
        printf("\nEnter the coefficient of x^%d: ", i);
        scanf("%f", &F[i]);
    }
    Again:
    printf("\nEnter the point at which the polynomial is to be divided: ");
    scanf("%f", &r);
    for(i=degree; i>0; i--)
    {
        b2 = F[i] + r * b1;
        B[i-1] = b2;
        b1 = b2;
    }
    printf("\nThe quotient of polynomial when divided at x = %.2f is  ", r);
    for(i=degree-1; i>0; i--)
    {
        printf("%.2fx^%d + ", B[i], i);
    }
    printf("%.2f", B[i]);
    printf("\nDo you want to find quotient another point(1. Yes 2. No): ");
    scanf("%d", &ch);
    if (ch == 1)
        goto Again;
    return 0;
}