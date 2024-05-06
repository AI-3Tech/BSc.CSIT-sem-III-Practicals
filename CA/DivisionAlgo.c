#include <stdio.h>

// Function to perform the division algorithm for subtraction
void restoring_algorithm(int a, int b) {
    int diff = a - b; // Difference
    int sign = diff >> 31; // Sign of the difference

    printf("Performing subtraction using Division Algorithm:\n");
    printf("Step\tA\tB\tDiff\tResult\n");

    // Step 1
    printf("1\t%d\t%d\t%d\t", a, b, diff);
    if (sign == 0) {
        printf("Positive\n");
    } else {
        printf("Negative\n");
    }

    // Steps 2 to 4
    for (int i = 0; i < 3; i++) {
        diff <<= 1; // Left shift diff
        printf("%d\t%d\t%d\t%d\t", i + 2, a, b, diff);
        if (sign == 0) {
            if (diff < 0) {
                diff += b; // Restore
                printf("Restored\n");
            } else {
                printf("No Restore\n");
            }
        } else {
            if (diff >= 0) {
                diff -= b; // Restore
                printf("Restored\n");
            } else {
                printf("No Restore\n");
            }
        }
    }

    printf("Final Result: %d\n", diff);
}

int main() {
    int a, b;

    printf("Enter two numbers (A and B) for subtraction: ");
    scanf("%d %d", &a, &b);

    restoring_algorithm(a, b);

    return 0;
}