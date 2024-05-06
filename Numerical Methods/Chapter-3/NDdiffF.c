//Program to implement Newton's Divided Difference Formula(Forward) to calculate first and second derivative of function

#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, k, n;
    float X[10], Y[10], x, fdx1, fdx2, factor, term; 
    printf("Enter the no. of data points: ");
    scanf("%d", &n);
    printf("\nEnter the data points");
    for(i=0; i<n; i++)
    {
        printf("\nX%d = ", i);
        scanf("%f", &X[i]);
    }
    printf("\nEnter the functional values");
    for(i=0; i<n; i++)
    {
        printf("\nF(x%d) = ", i);
        scanf("%f", &Y[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>i; j--)
        {
            Y[j] = (Y[j] - Y[j-1])/(X[j] - X[j-i-1]);
        }
    }

    printf("\nEnter the value at which derivative is to be calculated: ");
    scanf("%f", &x);

    fdx1 = Y[1];
    for(i=2; i<n; i++)
    {
        term = 0;
        for(j=0; j<i; j++)
        {
            factor = 1;
            for(k=0; k<i; k++)
            {
                if(k!=j)
                    factor = factor * (x - X[k]);
            }
            term = term + factor;
        }
        fdx1 = fdx1 + Y[i] * term;
    }
    printf("\nThe first derivative at x = %.2f is %.3f", x, fdx1);
    return 0;
}