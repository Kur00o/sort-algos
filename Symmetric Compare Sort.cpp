#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// A symmetric comparison function
// Returns: 
//  -1 if a < b
//   0 if a == b
//   1 if a > b
int symmetricCompare(int a, int b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

// Symmetric Sort implementation using the divide-and-conquer approach
vector<int> symmetricSort(vector<int>& arr) {
    // Base case: arrays of size 0 or 1 are already sorted
    if (arr.size() <= 1) {
        return arr;
    }

    // Select a pivot (middle element to avoid worst case)
    size_t pivot_idx = arr.size() / 2;
    int pivot = arr[pivot_idx];
    
    // Partition arrays based on symmetric comparison
    vector<int> less_than, equal_to, greater_than;
    
    for (size_t i = 0; i < arr.size(); i++) {
        int comparison = symmetricCompare(arr[i], pivot);
        
        if (comparison < 0) {
            less_than.push_back(arr[i]);
        } else if (comparison > 0) {
            greater_than.push_back(arr[i]);
        } else {
            equal_to.push_back(arr[i]);
        }
    }
    
    // Recursively sort the less_than and greater_than partitions
    less_than = symmetricSort(less_than);
    greater_than = symmetricSort(greater_than);
    
    // Combine the sorted partitions
    vector<int> result;
    result.insert(result.end(), less_than.begin(), less_than.end());
    result.insert(result.end(), equal_to.begin(), equal_to.end());
    result.insert(result.end(), greater_than.begin(), greater_than.end());
    
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> sorted_arr = symmetricSort(arr);
    
    cout << "Sorted array: ";
    for (int num : sorted_arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}