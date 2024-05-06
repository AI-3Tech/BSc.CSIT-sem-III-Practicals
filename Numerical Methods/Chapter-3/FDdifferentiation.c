//Program to calculate First Derivative using Newton's Forward Difference Formula

#include<stdio.h>
#include<math.h>

int Fact(int i)
{
    if(i==0)
        return 1;
    else 
        return (i * Fact(i-1));
}

int main()
{
    int i, j, n;
    float X[10], FD[10], s, x, h, term1, term2, previous, fdx; 
    printf("Enter the no. of data points: ");
    scanf("%d", &n);
    Again:
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
        scanf("%f", &FD[i]);
    }
    printf("\nEnter the value of x at which derivative is to be calculated: ");
    scanf("%f", &x);
    
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>i; j--)
        {
            FD[j] =  (FD[j]-FD[j-1]);
        }
    }
    h = X[1] - X[0];
    s = (x - X[0])/h;

    //Calculating the first derivative
    fdx = FD[1];
    previous = 1;
    for(i=2; i<n; i++)
    {
        term1 =  1;
        for(j=2; j<=i; j++)
        {
            term1 = term1 * (s-(j-2));
        }
        term2 = (s-(i-1))*previous;
        previous = (term1 + term2);
        fdx = fdx + (FD[i]*(term1 + term2))/Fact(i);
    }
    fdx = fdx/h;
    printf("\nThe first derivative is %.2f", fdx);
    return 0;
}