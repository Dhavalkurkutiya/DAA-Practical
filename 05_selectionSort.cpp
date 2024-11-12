// Time Complexity:
// Best Case: O(n²)
// Average Case: O(n²)
// Worst Case: O(n²)

#include <iostream>
using namespace std;

// [4, 3, 2, 1]


void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: \n";
    printArray(arr, n);

    cout << "\nAfter Sorting: \n";
    selectionSort(arr, n);

    printArray(arr, n);
    return 0;
}