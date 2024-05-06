//C program to implement Newton's Divided Difference Interpolation Polynomial

#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, n;
    float X[10], DD[10], L[10], x, sum=0; 
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
        scanf("%f", &DD[i]);
    }
    printf("\nEnter the value of x at which functional value is to be calculated: ");
    scanf("%f", &x);
    
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>i; j--)
        {
            DD[j] =  (DD[j]-DD[j-1])/(X[j] - X[j-(i+1)]);
        }
    }
    L[0] = 1;
    for(i=0; i<n-1; i++)
    {
        L[i+1] = L[i] * (x - X[i]);
    }
    for(i=0; i<n; i++)
    {
        sum = sum + DD[i]*L[i];
    }
    printf("\nAt x = %f \nF(%f) = %f", x, x, sum);
    return 0;
}