//C program to implement Lagrange's Interpolation formula

#include<stdio.h>
#include<math.h>

float L(float X[], float x, int i, int n)
{
    int j;
    float result= 1;
    for(j=0; j<n; j++)
    {
        if(j != i)
        {
            result = result * ((x - X[j])/(X[i]-X[j]));
        }
    }
    return result;
}

int main()
{
    int i, n;
    float x, X[15], FX[15], Pn=0;
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
        printf("\nFx%d = ", i);
        scanf("%f", &FX[i]);
    }
    printf("\nEnter the data point at which the functional value is to be calculated: ");
    scanf("%f", &x);
    
    for(i=0; i<n; i++)
    {
        Pn = Pn + FX[i]  * L(X, x, i, n);
    }
    printf("\nAt x = %f \nF(%f) = %f", x, x, Pn);
    return 0;
}