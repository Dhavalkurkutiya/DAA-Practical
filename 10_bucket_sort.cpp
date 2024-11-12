#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // 1. Create n empty buckets
    vector<vector<float>> buckets(n);

    // 2. Insert elements into different buckets based on their value
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // index in bucket
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 3. Sort each bucket
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 4. Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float value : buckets[i]) {
            arr[index++] = value;
        }
    }
}

int main() {
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    
    cout << "Unsorted array: ";
    for (float value : arr) {
        cout << value << " ";
    }
    cout << endl;

    bucketSort(arr);

    cout << "Sorted array: ";
    for (float value : arr) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
