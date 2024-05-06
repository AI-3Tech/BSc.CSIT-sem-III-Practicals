//C program to implement Newton's Background Difference Interpolation Polynomial

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
    int i, j, n, k;
    float X[10], BD[10], L[10], s, x, sum=0; 
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
        scanf("%f", &BD[i]);
    }
    printf("\nEnter the value of x at which functional value is to be calculated: ");
    scanf("%f", &x);
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            BD[j] =  (BD[j+1]-BD[j]);
        }
    }
    s = (x - X[n-1])/(X[1] - X[0]);
    L[0] = 1;
    for(i=0; i<n; i++)
    {
        L[i+1] = L[i] * (s + i);
    }
    for(i=0; i<n; i++)
    {
        sum = sum + (BD[n-i-1]*L[i])/Fact(i);
    }
    printf("\nAt x = %.3f \nF(%.3f) = %.3f", x, x, sum);
    return 0;
}