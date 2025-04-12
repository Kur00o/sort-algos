#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Utility function to check if an array is sorted
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

// Factorial Sort implementation
vector<int> factorialSort(vector<int> arr) {
    // Return immediately if array is empty or has only one element
    if (arr.size() <= 1) {
        return arr;
    }
    
    // Try all permutations until we find a sorted one
    while (!isSorted(arr)) {
        // Generate the next permutation
        next_permutation(arr.begin(), arr.end());
    }
    
    return arr;
}

// A more practical implementation that doesn't rely on finding all permutations
vector<int> practicalFactorialSort(const vector<int>& arr) {
    // Create a copy of the input array
    vector<int> result = arr;
    
    // Sort the array using STL sort (or any other efficient algorithm)
    sort(result.begin(), result.end());
    
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements (small number recommended): ";
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
    
    // Warning for large arrays
    if (n > 10) {
        cout << "Warning: Factorial Sort is extremely inefficient for large arrays." << endl;
        cout << "Using a practical implementation instead." << endl;
        vector<int> sorted_arr = practicalFactorialSort(arr);
        
        cout << "Sorted array: ";
        for (int num : sorted_arr) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        vector<int> sorted_arr = factorialSort(arr);
        
        cout << "Sorted array: ";
        for (int num : sorted_arr) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}