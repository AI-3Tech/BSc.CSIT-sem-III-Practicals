#include <iostream>
using namespace std;

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];

    cout << endl;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        cout << "\nPass " << i + 1 << std::endl;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                printArray(arr, n);
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

// Driver program to test above functions
int main()
{
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array:" << endl;
    printArray(arr, N);

    bubbleSort(arr, N);

    cout << "\nSorted array:" << endl;
    printArray(arr, N);

    return 0;
}