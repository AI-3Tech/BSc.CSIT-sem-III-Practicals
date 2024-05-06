//C program to implement Newton Raphson Method

#include<stdio.h>
#include<math.h>
#define EPS 0.0001
#define MAX 20

float FN(float root, float A[], int degree)
{
	int i;
	float result = A[0];
	for (i = 1; i <= degree; i++)
	{
		result = result + A[i]*pow(root, i);
	}
	return result;
}

int main()
{
	int i, degree, iteration = 0;
	float x0, xn, fx, fdx, F[10], FD[10];
	printf("Enter the degree of the function: ");
	scanf("%d", &degree);
	printf("\nEnter the coefficients of the given function\n");
	for (i = 0; i <= degree; i++)
	{
		printf("\nEnter the coefficient of x^%d: ", i);
		scanf("%f", &F[i]);
	}
	printf("\nNow enter the coefficients of the function derivative\n");
	for (i = 0; i < degree; i++)
	{
		printf("\nEnter the coefficient of x^%d: ", i);
		scanf("%f", &FD[i]);
	}
	printf("\nEnter the initial guess: ");
	scanf("%f", &x0);

	do
	{
		fx = FN(x0, F, degree);
		fdx = FN(x0, FD, degree);
		xn = x0 - (fx / fdx);
		if (fabs((xn - x0)/xn) < EPS)
		{
			iteration++;
			printf("\nRoot = %f ", xn);
			printf("\nFunctional value at %f = %f ", xn, FN(xn, F, degree));
			printf("\nNo. of iterations = %d ", iteration);
			printf("\n");
			break;
		}
		else
		{
			x0 = xn; 
			iteration++;
			if (iteration > MAX)
			{
				printf("\nSOLUTION DOESN'T CONVERGE \n");
				printf("IN %d ITERATIONS \n", MAX);
				break;
			}
		}
	}while(1);
	return 0;
}