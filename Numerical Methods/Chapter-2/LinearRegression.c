#include<stdio.h>
#include<math.h>

int main()
{
    int i, n;
    float a, b, X[10], Y[10], sx = 0, sx2 = 0, sy = 0, sxy = 0;
    printf("Enter the no. of data points: ");
    scanf("%d", &n);
    printf("\nEnter the data points and their corresponding functional values, pairwise");
    for(i = 0; i<n; i++)
    {
        printf("\nX%d and Y%d: ", i, i);
        scanf("%f %f", &X[i], &Y[i]);
    }
    for(i =0; i<n; i++)
    {
        sx = sx + X[i];
        sy = sy + Y[i];
        sx2 = sx2 + X[i]*X[i];
        sxy = sxy + X[i]*Y[i];
    }
    b = (n*sxy - sx*sy)/(n*sx2 - sx*sx);
    a = sy/(float)n - b*sx/(float)n;
    printf("\nb = %.3f \t a = %.3f", b, a);
    printf("\nThe linear fitted equation is \t Y = %.3f + %.3fx", a, b);
    return 0;
}