#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int merged[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            merged[k++] = arr[i++];
        } else {
            merged[k++] = arr[j++];
        }
    }
    
    while (i <= mid) {
        merged[k++] = arr[i++];
    }
    
    while (j <= right) {
        merged[k++] = arr[j++];
    }
    
    for (int x = 0, y = left; x < k; x++, y++) {
        arr[y] = merged[x];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
