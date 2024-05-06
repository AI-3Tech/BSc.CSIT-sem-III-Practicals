//C program to implement Bisection Method

#include<stdio.h>
#include<math.h>
#define EPS 0.00001 

float F(float r, float A[], int degree)
{
	int i;
	float result = A[0];
	for (i = 1; i <= degree; i++)
	{
		result = result + A[i] * pow(r, i);
	}
	return result;
}
int main()
{
	int degree, i, iteration = 0, ch;
	float r1, r2, mp, fr, fr1, fr2, A[10], check;
	printf("Enter the degree of the polynomial: ");
	scanf("%d", &degree);
	for (i = 0; i <= degree; i++)
	{
		printf("\nEnter the coefficient of x^%d: ", i);
		scanf("%f", &A[i]);
	}

	Again:
	printf("Enter the starting points: ");
	scanf("%f %f", &r1, &r2);
	fr1 = F(r1, A, degree);
	fr2 = F(r2, A, degree);
	do
	{
		mp = (r1 + r2) / 2;
	fr = F(mp, A, degree);
	if (fr1 * fr2 > 0)
	{
		printf("Either the starting points doesn't bracket the roots or the given range is too wide");
		printf("\nDo you want to give another interval (1. Yes 2. No)");
		scanf("%d", &ch);
		if(ch == 1)
			goto Again;
		else
			return 0;
	}
	else if(fr == 0)
	{
		iteration++;
		printf("\nRoot = %f", mp);
		printf("\nIteration(s): %d", iteration);
		return 0;
	}
	else if (fr1 * fr < 0)
	{
		iteration++;
		r2 = mp;
	}
	else
	{
		iteration++;
		r1 = mp;
	}
	check = fabs(r2 - r1);
	if (check <= EPS)
	{
		printf("\nRoot = %f", mp);
		printf("\nIteration = %d", iteration);
	}
	} while (check > EPS);
	return 0;
}