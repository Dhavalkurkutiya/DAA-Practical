#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target){
    int st = 0;
    int end = arr.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st)/2; // safer way to calculate mid
         
        if(target == arr[mid]){
            return mid; // return index when target found
        }
        else if(target < arr[mid]){
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr1 = {-1, 0, 3, 5, 9, 12};
    int target = 9;


    cout << binarySearch(arr1, target) << endl;

    

}
