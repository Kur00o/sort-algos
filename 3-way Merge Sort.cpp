#include <iostream>
#include <vector>
using namespace std;

// Merge function for 3-way merge sort
// Merges arr[low...mid1], arr[mid1+1...mid2] and arr[mid2+1...high]
void merge(vector<int>& arr, int low, int mid1, int mid2, int high) {
    // Create temporary arrays
    vector<int> temp(high - low + 1);
    
    // Index pointers for the three sub-arrays
    int i = low;       // First sub-array index
    int j = mid1 + 1;  // Second sub-array index
    int k = mid2 + 1;  // Third sub-array index
    int l = 0;         // Temp array index
    
    // Merge the three sub-arrays
    while (i <= mid1 && j <= mid2 && k <= high) {
        if (arr[i] <= arr[j] && arr[i] <= arr[k]) {
            temp[l++] = arr[i++];
        } else if (arr[j] <= arr[i] && arr[j] <= arr[k]) {
            temp[l++] = arr[j++];
        } else {
            temp[l++] = arr[k++];
        }
    }
    
    // Merge remaining elements of first and second sub-arrays
    while (i <= mid1 && j <= mid2) {
        if (arr[i] <= arr[j]) {
            temp[l++] = arr[i++];
        } else {
            temp[l++] = arr[j++];
        }
    }
    
    // Merge remaining elements of first and third sub-arrays
    while (i <= mid1 && k <= high) {
        if (arr[i] <= arr[k]) {
            temp[l++] = arr[i++];
        } else {
            temp[l++] = arr[k++];
        }
    }
    
    // Merge remaining elements of second and third sub-arrays
    while (j <= mid2 && k <= high) {
        if (arr[j] <= arr[k]) {
            temp[l++] = arr[j++];
        } else {
            temp[l++] = arr[k++];
        }
    }
    
    // Copy remaining elements from first sub-array
    while (i <= mid1) {
        temp[l++] = arr[i++];
    }
    
    // Copy remaining elements from second sub-array
    while (j <= mid2) {
        temp[l++] = arr[j++];
    }
    
    // Copy remaining elements from third sub-array
    while (k <= high) {
        temp[l++] = arr[k++];
    }
    
    // Copy back the merged elements to original array
    for (i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }
}

// Recursive 3-way merge sort function
void threeWayMergeSort(vector<int>& arr, int low, int high) {
    // Base case: If array segment has 1 or 0 elements
    if (high <= low) {
        return;
    }
    
    // Calculate the two mid points that divide array into three parts
    int mid1 = low + (high - low) / 3;
    int mid2 = low + 2 * (high - low) / 3;
    
    // Sort the three parts recursively
    threeWayMergeSort(arr, low, mid1);
    threeWayMergeSort(arr, mid1 + 1, mid2);
    threeWayMergeSort(arr, mid2 + 1, high);
    
    // Merge the sorted arrays
    merge(arr, low, mid1, mid2, high);
}

// Wrapper function
vector<int> threeWayMergeSort(vector<int>& arr) {
    // Create a copy of the original array
    vector<int> result = arr;
    
    // Sort the array
    threeWayMergeSort(result, 0, result.size() - 1);
    
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
    
    vector<int> sorted_arr = threeWayMergeSort(arr);
    
    cout << "Sorted array: ";
    for (int num : sorted_arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}