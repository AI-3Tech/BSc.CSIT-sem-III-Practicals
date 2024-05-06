#include <stdio.h>

// Function to generate parity bit for even parity
int generateParityEven(int data[], int n) {
    int parity = 0;
    for (int i = 0; i < n; i++) {
        parity ^= data[i];
    }
    return parity;
}

// Function to generate parity bit for odd parity
int generateParityOdd(int data[], int n) {
    int parity = 1; // Initialize with 1 for odd parity
    for (int i = 0; i < n; i++) {
        parity ^= data[i];
    }
    return parity;
}

// Function to check parity for even parity
int checkParityEven(int data[], int n, int receivedParity) {
    int calculatedParity = generateParityEven(data, n);
    return receivedParity == calculatedParity;
}

// Function to check parity for odd parity
int checkParityOdd(int data[], int n, int receivedParity) {
    int calculatedParity = generateParityOdd(data, n);
    return receivedParity == calculatedParity;
}

int main() {
    int n;
    printf("Enter the number of bits for data: ");
    scanf("%d", &n);

    int data[n];
    printf("Enter the data bits (0/1): ");
    for (int i = 0; i < n; i++) {
        scanf("%1d", &data[i]);
    }

    int choice;
    printf("Choose Parity Type:\n");
    printf("1. Even Parity\n");
    printf("2. Odd Parity\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int parityBit, isValid;
    switch (choice) {
        case 1:
            parityBit = generateParityEven(data, n);
            printf("Generated Even Parity Bit: %d\n", parityBit);
            printf("Enter the received parity bit: ");
            scanf("%d", &parityBit);
            isValid = checkParityEven(data, n, parityBit);
            break;
        case 2:
            parityBit = generateParityOdd(data, n);
            printf("Generated Odd Parity Bit: %d\n", parityBit);
            printf("Enter the received parity bit: ");
            scanf("%d", &parityBit);
            isValid = checkParityOdd(data, n, parityBit);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    if (isValid) {
        printf("Parity Check: The data is correct.\n");
    } else {
        printf("Parity Check: The data has been changed.\n");
    }

    return 0;
}