#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1]) 
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
           if (arr[j] < arr[minIndex])
           {
            minIndex = j;
           }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int curr = arr[i];
        int prev = i-1;

        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 2 , 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: \n";
    printArray(arr, n);

    insertionSort(arr, n);
    
    cout << "After Sorting: \n";
    printArray(arr, n);

    return 0;
}
