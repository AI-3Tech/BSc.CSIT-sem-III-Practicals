#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
    int i, j, k, m, n;
    float A[10][10], B[10], Z[10], X[10], FX[10], sum, pivot, term;
    printf("Enter the no. of data points: ");
    scanf("%d", &n);
    printf("\nEnter the degree of polynomial to be fitted: ");
    scanf("%d", &m);
    printf("\nEnter the data points: ");
    for(i=0; i<n; i++)
    {
        scanf("%f %f", &X[i], &FX[i]);
    }

    for(i=0; i<=m; i++)
    {
        for(j=0; j<=m; j++)
        {
            sum = 0;
            for(k=0; k<n; k++)
            {
                sum += pow(X[k], i+j);
            }
            A[i][j] = sum;
        }
    }

    for(i=0; i<=m; i++)
    {
        sum = 0;
        for(j=0; j<n; j++)
        {
            sum += FX[j]*pow(X[j], i);
        }
        B[i] = sum;
    }
    for(i=0; i<m; i++)
    {
        pivot = A[i][i];
        if(pivot == 0)
        {
            printf("\nMethod Failed");
            return 0;
        }    
        else
        {
            for(j=i+1; j<=m; j++)
            {
                term = A[j][i]/pivot;
                for(k=0; k<=m; k++)
                    A[j][k] = A[j][k] - A[i][k]*term;
                B[j] = B[j] - B[i]*term;
            }
        }
    }
    Z[m] = B[m]/A[m][m];
    for(i=m-1; i>=0; i--)
    {
        sum = 0;
        for(j=i+1; j<=m; j++)
        {
            sum = sum + A[i][j] * Z[j];
        }
        Z[i] = (B[i] - sum)/A[i][i];
    }
    printf("\nThe polynomial of regression is : \n");
    printf("y = %.3f + %.3fx", Z[0], Z[1]);
    for(i=2; i<=m; i++)
        printf("+ %.3fx^%d", Z[i], i);
    getch();
    return 0;
}