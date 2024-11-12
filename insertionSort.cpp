//1. bubbleSort
//2. selectionSort
//3. insertionSort

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    // Time Complexity:
    // Best Case: O(n)
    // Average Case: O(n²)
    // Worst Case: O(n²)
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i-1;

        while (prev >= 0 && arr[prev] > curr )
        {
          arr[prev+1] = arr[prev];
          prev--;
        }
        arr[prev+1] = curr; 
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
    insertionSort(arr, n);

    printArray(arr, n);
    return 0;
}