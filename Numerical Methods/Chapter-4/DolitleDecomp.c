#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, k, n;
    float Matrix[10][10], U[10][10], L[10][10], sum = 0, B[10], Z[10], X[10];
    printf("Enter the dimension of the matrix: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the Matrix\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%f", &Matrix[i][j]);
        }
    }
    printf("\nEnter the elements constant matrix row-wise: ");
    for(i=0; i<n; i++)
    {
        scanf("%f", &B[i]);
    } 

    //Computing L and U matrices
    for(j=0; j<n; j++)
    {
        U[0][j] = Matrix[0][j];
    }
    for(i=0; i<n; i++)
    {
        L[i][i] = 1;
    }
    for(i=1; i<n; i++)
    {
        L[i][0] = Matrix[i][0] / U[0][0];
    }
    for(i=1; i<n; i++)
    {
        for(j=1; j<=i; j++)
        {
            for(k=0; k<j; k++)
            {
                sum = sum + (L[i][k] * U[k][i]);
            }
            U[j][i] = Matrix[j][i] - sum;
            sum = 0;
        }
        for(j=i+1; j<n; j++)
        {
            for(k=0; k<=i-1; k++)
            {
                sum = sum + (L[j][k] * U[k][i]);
            }
            L[j][i] = (Matrix[j][i] - sum)/U[i][i];
            sum = 0;
        }
    }

    //computing Z using forward substitution
    Z[0] = B[0];
    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            sum = sum + (L[i][j]*Z[j]);
        }
        Z[i] = B[i] - sum;
        sum = 0;
    }

    //Computing solution matrix
    X[n-1] = Z[n-1]/U[n-1][n-1];
    for(i=n-2; i>=0; i--)
    {
        for(j=i+1; j<n; j++)
            sum = sum + (U[i][j]*X[j]);
        X[i] = (Z[i] - sum)/U[i][i];
        sum = 0;
    }

    printf("\nLower Matrix \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("\t%.2f", L[i][j]);
        }
        printf("\n");
    }
    printf("\nUpper Matrix \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("\t%.2f", U[i][j]);
        }
        printf("\n");
    }

    printf("\nSolution:");
    for(i=0; i<n; i++)
    {
        printf("\nx%d = %.3f", i+1, X[i]);
    }
    return 0;
}