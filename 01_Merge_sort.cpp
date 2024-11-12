#include <iostream>
using namespace std;

//Time Complexity: O(nlogn)
//Space Complexity: O(n)
//Stable Sorting Algorithm


void conquer(int arr[], int si, int mid, int ei){
    int merged[ei - si + 1];
    int idx1 = si;
    int idx2 = mid+1;
    int x = 0;

    while (idx1 <= mid && idx2 <= ei)
    {
        if (arr[idx1] <= arr[idx2])
        {
            merged[x++] = arr[idx1++];
        }
        else{
            merged[x++] = arr[idx2++];
        }
    }

    while (idx1 <= mid){
        merged[x++] = arr[idx1++];
    }

    while (idx2 <= ei){
        merged[x++] = arr[idx2++];
    }

    for (int i = 0, j = si; i < (ei - si + 1); i++, j++)
    {
        arr[j] = merged[i];
    }
}

void divide(int arr[], int si, int ei){
    if (si >= ei)
    {
        return;
    }
    
    int mid = si + (ei - si)/2; // (si+ei)/2 (to avoid overflow)
    divide(arr, si, mid);
    divide(arr, mid+1, ei);
    conquer(arr, si, mid, ei);

}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 1, 5, 4, 2};
    int n = 5;
    divide(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
