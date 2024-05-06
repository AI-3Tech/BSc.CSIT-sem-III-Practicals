#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, k, n;
    float Matrix[10][10], Const[10], E[10], previous_x[10], new_x[10], sum, error;
    printf("Enter the no. of variables in the system of equations: ");
    scanf("%d", &n);
    printf("\nEnter the coefficients row-wise\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%f", &Matrix[i][j]);
        }
    }
    printf("\nEnter the values of constants row-wise\n");
    for(i=0; i<n; i++)
    {
        scanf("%f", &Const[i]);
    }
    printf("\nEnter the Accuracy Limit: ");
    scanf("%f", &error);

    for(i=0; i<n; i++)
    {
        new_x[i] = 0;
    }
    while(1)
    {
        for(i=0; i<n; i++)
        {
            sum = Const[i];
            for(j=0; j<n; j++)
            {
                if(i!=j)
                   {
                    sum = sum - (Matrix[i][j] * new_x[j]);
                   } 
            }
            previous_x[i] = new_x[i];
            new_x[i] = sum/Matrix[i][i];
            if(new_x[i] == 0)
            {
                E[i] = fabs(previous_x[i]);
            }
            else
                E[i] = fabs(new_x[i] - previous_x[i])/fabs(new_x[i]);
        }
        for(i=0; i<n; i++)
        {
            if(E[i]>error)
                break;
        }
        if(i==n)
            break;
        else
            continue;
    }

    printf("\nSolution: \n");
    for(i=0; i<n; i++)
    {
        printf("%.2f\t", new_x[i]);
    }
    return 0;
}