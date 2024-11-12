#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n)
{
    // Time Complexity:
    // Best Case: O(n)
    // Average Case: O(n²)
    // Worst Case: O(n²)
    
    bool isSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return;
        }
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: \n";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "After Sorting: \n";
    printArray(arr, n);

    return 0;
}
