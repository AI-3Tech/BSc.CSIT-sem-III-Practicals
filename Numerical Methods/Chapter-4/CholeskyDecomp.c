#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, k, n;
    float Matrix[10][10], L[10][10], U[10][10], temp, B[10], sum =0, Z[10], X[10];
    printf("Enter the dimension of the matrix: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the coefficient matrix\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%f", &Matrix[i][j]);
        }
    }
    printf("\nEnter the elements of the constant matrix: \n");
    for(i=0; i<n; i++)
    {
        scanf("%f", &B[i]);
    }

    //Calculate the elements of the Upper Matrix
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            temp =0;
            if(i==j)
            {
                for(k=0; k<j; k++)
                {
                    temp = temp + (U[k][i] * U[k][i]);
                }
                U[i][i] = sqrt(Matrix[i][i] - temp);
            }
            else if(j>i)
            {
                for(k=0; k<i; k++)
                {
                    temp = temp + (U[k][i] * U[k][j]);
                }
                U[i][j] = (1/U[i][i])*(Matrix[i][j] - temp);
            }
            else
            {
                U[i][j] = 0;
            }
        }
    }

    //Finding Transpose i.e Lower Matrix
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            L[i][j] = U[j][i];
        }
    }

    //computing Z using forward substitution
    Z[0] = B[0]/L[0][0];
    printf("\nz%d = %f", 0, Z[0]);
    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            sum = sum + (L[i][j]*Z[j]);
        }
        Z[i] = (B[i] - sum)/L[i][i];
        sum = 0;
        printf("\nz%d = %f", i, Z[i]);
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

    printf("\n\tLower Matrix\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("\t%.2f", L[i][j]);
        }
        printf("\n");
    }

    printf("\n\tUpper Matrix\n");
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