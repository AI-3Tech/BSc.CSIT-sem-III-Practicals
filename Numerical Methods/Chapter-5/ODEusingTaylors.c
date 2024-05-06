#include<stdio.h>
#include<math.h>
#define YwrtX  x-y*y

int Fact(int n)
{
    if (n==1)
        return 1;
    else 
        return (n*Fact(n-1));
    return 0;
}

int main()
{
    float x, a, b, y, fdy, sdy, tdy;
    printf("Enter the initial values of x and y: ");
    scanf("%f %f", &a, &b);
    printf("\nEnter value of x at which function is to be evaluated: ");
    scanf("%f", &x);
    fdy = a - b*b;
    printf("\nfdy = %f", fdy);
    sdy = 1 - 2*b*fdy;
    printf("\nsdy  = %f", sdy);
    tdy = -2*fdy*fdy - 2*b*sdy;
    printf("\ntdy = %f", tdy);
    y = b + (x-a)*fdy + (x-a)*(x-b)*sdy/Fact(2) + (x-a)*(x-a)*(x-a)*tdy/Fact(3);
    printf("\nThe functional value at x = %.3f is %f" , x, y);
    return 0;
}