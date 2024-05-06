//C Program to implement Fixed Point Method

#include<stdio.h>
#include<math.h>
#define E 0.0001
#define MAX 20

float FN(float F[], float r, int degree)
{
    int i;
    float result = 0;
    for(i=2; i<= degree; i++)
    {
        result = result + F[i] * pow(r, i); 
    }
    result = (-F[0] - result) / F[1];
    return result;
}

int main()
{
    int i, iteration = 1, degree, ch, count = 0;
    float r0, r1, rn, F[10], check;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    printf("\nEnter the coefficients of the polynomial(It should be of form: y = f(x))");
    for(i=0; i<= degree; i++)
    {
        printf("\nEnter the coefficient of x^%d: ", i);
        scanf("%f", &F[i]);
    }
    Again:
    printf("\nEnter the initial guess: ");
    scanf("%f", &r0);
    count++;
    r1 = FN(F, r0, degree);
    if(fabs(r1-r0)<E)
    {
        printf("\nRoot = %f", r1);
        printf("\nIteration = %d", iteration);
        return 0;
    }
    do
    {
        iteration++;
        rn = FN(F, r1, degree);
        check = fabs(rn-r1);
        r1 = rn;
        if(iteration > MAX)
        {
            printf("\nRoot didn't converge within %d iteration", MAX);
            return 0;
        }
    }while(check >= E);
    printf("\nRoot = %f", rn);
    printf("\nIteration = %d", iteration);
    if(count < degree)
    {
        printf("\nDo you want to find another root(1. Yes 2. No): ");
        scanf("%d", &ch);
        if (ch ==1)
            goto Again;
    }
    return 0;
}