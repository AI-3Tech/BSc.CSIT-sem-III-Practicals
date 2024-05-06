//Program to compute Inversion Matrix using Gauss Jordan Method

#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, k, p, q, s=1, n;
    float AugmMat[10][11], x[10], pivot, term;
    printf("Enter the dimension of the matrix: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the matrix row-wise\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("\nAugmentedMatrix[%d][%d] = ", i, j);
            scanf("%f", &AugmMat[i][j]);
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=n; j<2*n; j++)
        {
            if(i==j-n)
                AugmMat[i][j] = 1;
            else 
                AugmMat[i][j] = 0;
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
            for(p=0; p<2*n; p++)
            {
                AugmMat[i][p] = AugmMat[i][p]/pivot;
            }
            printf("\nStep-%d\n", s);
            for(p=0; p<n; p++)
            {
                for(q=0; q<2*n; q++)
                {
                    printf("%4.2f  ", AugmMat[p][q]);
                    if(q == n-1)
                        printf(":  ");
                }
                printf("\n");
            }
            s++;

            for(k=0; k<n; k++)
            {
                term = AugmMat[k][i];
                if(k!=i)
                {
                    for(j=0; j<2*n; j++)
                    {
                        AugmMat[k][j] = AugmMat[k][j] - AugmMat[i][j] * term;
                    }
                }
            }
        }
        printf("\nStep-%d\n", s);
        for(p=0; p<n; p++)
        {
            for(q=0; q<2*n; q++)
            {
                printf("%4.2f  ", AugmMat[p][q]);
                if(q==n-1)
                    printf(":  ");
            }
            printf("\n");
        }
        s++;
    }

    printf("\nThe Inversion Matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=n; j<2*n; j++)
        {
            printf("%4.2f  ", AugmMat[i][j]);
        }
        printf("\n");
    }
    return 0;
}