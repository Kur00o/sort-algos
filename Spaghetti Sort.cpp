#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> spaghetti_sort(const vector<int>& arr) {
    if (arr.empty()) {
        return {};
    }
    
    // Find the maximum value in the array
    int max_value = *max_element(arr.begin(), arr.end());
    
    // Create a vector of buckets (0 to max_value)
    vector<int> buckets(max_value + 1, 0);
    
    // Fill buckets - count occurrences of each value
    for (int num : arr) {
        buckets[num]++;
    }
    
    // Generate the sorted array
    vector<int> sorted_arr;
    for (int value = 0; value <= max_value; value++) {
        // Add each value to result array 'count' times
        for (int count = 0; count < buckets[value]; count++) {
            sorted_arr.push_back(value);
        }
    }
    
    return sorted_arr;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " non-negative integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        
        // Validate input
        if (arr[i] < 0) {
            cout << "Error: Spaghetti sort only works with non-negative integers." << endl;
            return 1;
        }
    }
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> sorted_arr = spaghetti_sort(arr);
    
    cout << "Sorted array: ";
    for (int num : sorted_arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}