#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, k, p, q, s=1, n;
    float AugmMat[10][11], x[10], pivot, term;
    printf("Enter no. of variables in the system of linear equations: ");
    scanf("%d", &n);
    printf("\nEnter the coefficients and constants of the equations row-wise\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
        {
            printf("\nAugmentedMatrix[%d][%d] = ", i, j);
            scanf("%f", &AugmMat[i][j]);
        }
    }

    //Gauss Jordan elimination
    for(i=0; i<n; i++)
    {
        pivot = AugmMat[i][i];
        if(fabs(pivot)<0.00001)
        {
            printf("\nOne of the Pivot element is zero so, cannot compute solution\n");
        }
        else
        {
            for(p=0; p<n+1; p++)
            {
                AugmMat[i][p] = AugmMat[i][p]/pivot;
            }
            printf("\nStep-%d\n", s);
            for(p=0; p<n; p++)
            {
                for(q=0; q<=n; q++)
                {
                    printf("%4.2f  ", AugmMat[p][q]);
                }
                printf("\n");
            }
            s++;

            for(k=0; k<n; k++)
            {
                term = AugmMat[k][i];
                if(k!=i)
                {
                    for(j=0; j<n+1; j++)
                    {
                        AugmMat[k][j] = AugmMat[k][j] - AugmMat[i][j] * term;
                    }
                }
            }
        }
        printf("\nStep-%d\n", s);
        for(p=0; p<n; p++)
        {
            for(q=0; q<=n; q++)
            {
                printf("%4.2f  ", AugmMat[p][q]);
            }
            printf("\n");
        }
        s++;
    }

    printf("\nSolution of the given equations are: ");
    for(i=0; i<n; i++)
    {
        printf("x%d = %.2f\t", i+1, AugmMat[i][n]);
    }
    return 0;
}