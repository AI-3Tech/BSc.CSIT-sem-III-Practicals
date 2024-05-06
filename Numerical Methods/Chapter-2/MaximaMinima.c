//C program to find Maxima and Minima using Newton's Forward Difference Interpolation

#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, n;
    double X[10], FD[10], s1, s2, x1, x2, a, b, c, h, value; 
    printf("Enter the no. of data points: ");
    scanf("%d", &n);
    Again:
    printf("\nEnter the data points");
    for(i=0; i<n; i++)
    {
        printf("\nX%d = ", i);
        scanf("%lf", &X[i]);
    }
    printf("\nEnter the functional values");
    for(i=0; i<n; i++)
    {
        printf("\nF(x%d) = ", i);
        scanf("%lf", &FD[i]);
    }
    
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>i; j--)
        {
            FD[j] =  (FD[j]-FD[j-1]);
        }
    }
    h = (X[1] - X[0]);
    a = (1/2.0) * FD[3];
    b = FD[2] - FD[3];
    c = FD[1] - (1/2.0) * FD[2] + (1/3.0) * FD[3];
    s1 = (-b + sqrt(b*b -4*a*c))/(2*a);
    s2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
    x1 = X[0] + s1*h;
    x2 = X[0] + s2*h;
    value = (FD[2] + (s1-1)*FD[3])/(h*h);
    if(value < 0)
    {
        printf("\nThe maxima lies at x = %.2f", x1);
    }
    else
        printf("\nThe Minima lies at x = %.2f", x1);
    
    value = (FD[2] + (s2-1)*FD[3])/(h*h);
    if(value < 0)
    {
        printf("\nThe Maxima lies at x = %.2f", x2);
    }
    else
    {
        printf("\nThe Minima lies at x = %.2f", x2);
    }
    return 0;
}