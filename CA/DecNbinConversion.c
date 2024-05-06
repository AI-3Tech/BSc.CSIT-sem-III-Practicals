#include<stdio.h>
#include<math.h>

int binary_to_decimal(int binary, int n);
int decimal_to_binary(int decimal);

int main() {
    int n, b, d;
    printf("Enter the number of bits of the binary number: ");
    scanf("%d", &n);
    printf("\nEnter the binary number: ");
    scanf("%d", &b);
    printf("\nEnter a decimal number: ");
    scanf("%d", &d);
    printf("\nThe binary to decimal is: %d", binary_to_decimal(b, n));
    printf("\nThe decimal to binary is: %d", decimal_to_binary(d));
    return 0;
}

int binary_to_decimal(int binary, int n) {
    int sum = 0, i = 0;
    while (binary != 0) {
        sum += (binary % 10) * pow(2, i);
        ++i;
        binary /= 10;
    }
    return sum;
}

int decimal_to_binary(int decimal) {
    int binary = 0, rem, place = 1;
    while (decimal != 0) {
        rem = decimal % 2;
        decimal /= 2;
        binary += rem * place;
        place *= 10;
    }
    return binary;
}