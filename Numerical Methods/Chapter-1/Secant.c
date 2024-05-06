//C program to implement the Secant Method

#include<stdio.h>
#include<math.h>
#define E 0.0001
#define MAX 20

float FN(float F[], float root, int degree)
{
    float result = F[0];
    int i;
    for(i = 1; i <= degree; i++)
    {
        result = result + F[i] * pow(root, i);
    }
    return result;
}

int main()
{
    int i, iteration = 0, degree;
    float r1, r2, rn, F[10], fr1, fr2, fn, ck;
    printf("Enter the degree of polynomial:");
    scanf("%d", &degree);
    for(i=0; i<=degree; i++)
    {
        printf("\nEnter the coefficient of x^%d: ", i);
        scanf("%f", &F[i]);
    }
    printf("\nEnter the initial points:");
    scanf("%f %f", &r1, &r2);

    fr1= FN(F, r1, degree);
    fr2= FN(F, r2, degree);
    
    do
    {
        iteration++;
        rn = r2 - (fr2*(r2 - r1))/(fr2 - fr1);
        fn = FN(F, rn, degree);
        if( fn == 0)
        {
            printf("\nRoot = %f", rn);
            printf("\nFunctional value at %f = %f", rn, fn);
            printf("\nIterations = %d", iteration);
            return 0;
        }
        r1 = r2;
        r2 = rn;
        fr1 = fr2;
        fr2 = fn;
        if(iteration > MAX)
        {
            printf("\nRoot didn't converge in %d iterations", MAX);
            return 0;
        }
        ck = fabs(r2 - r1);
    } while (ck >= E);

    printf("\nRoot = %f", rn);
    printf("\nFunctional value at %f = %f", rn, fn);
    printf("\nIterations = %d", iteration);
    return 0;
}