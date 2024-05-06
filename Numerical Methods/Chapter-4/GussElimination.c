#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, k, n;
    float ConstMat[10], CoeffMat[10][10], x[10], pivot, term, sum;
    printf("Enter no. of variables in the system of linear equations: ");
    scanf("%d", &n);
    printf("\nEnter the coefficients of the equations row-wise\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("\nCoeffMat[%d][%d] = ", i, j);
            scanf("%f", &CoeffMat[i][j]);
        }
    }
    printf("\nEnter the constants row-wise\n");
    for(i=0; i<n; i++)
    {
        printf("\nConstMat[%d] = ", i);
        scanf("%f", &ConstMat[i]);
    }

    //Forward elimination
    for(i=0; i<n-1; i++)
    {
        pivot = CoeffMat[i][i];
        if(fabs(pivot)<0.00001)
        {
            printf("\nOne of the Pivot element is zero so, cannot compute solution\n");
        }
        else
        {
            for(k=i+1; k<n; k++)
            {
                term = CoeffMat[k][i]/pivot;
                for(j=0; j<n; j++)
                {
                    CoeffMat[k][j] = CoeffMat[k][j] - CoeffMat[i][j] * term;
                }
                ConstMat[k] = ConstMat[k] - ConstMat[i] * term;
            }
        }
    }

    x[n-1] = ConstMat[n-1]/CoeffMat[n-1][n-1];
    
    //Backward substitution
    for(i=n-2; i>=0; i--)
    {
        sum = 0;
        for(j=i+1; j<n; j++)
        {
            sum = sum + CoeffMat[i][j]*x[j];
        }
        x[i] =(ConstMat[i] - sum)/CoeffMat[i][i];
    }
    printf("\nSolution of the given equations are: ");
    for(i=0; i<n; i++)
    {
        printf("x%d = %.2f\t", i+1, x[i]);
    }
    return 0;
}