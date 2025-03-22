// C++ implementation for the above approach.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// grail sort for returning the sorted array
vector<int> grailSort(vector<int> arr)
{
	// Split the array into blocks of size sqrt(n)
	int blockSize = sqrt(arr.size());
	int numBlocks
		= (arr.size() + blockSize - 1) / blockSize;
	vector<vector<int> > blocks(numBlocks);
	for (int i = 0; i < numBlocks; i++) {
		blocks[i].resize(blockSize);
		copy(arr.begin() + i * blockSize,
			arr.begin() + (i + 1) * blockSize,
			blocks[i].begin());
		// copying values from array to blocks

		// Sort the blocks using insertion sort
		for (int j = 1; j < blockSize; j++) {
			int key = blocks[i][j];
			int k = j - 1;
			while (k >= 0 && blocks[i][k] > key) {
				blocks[i][k + 1] = blocks[i][k];
				k--;
			}
			blocks[i][k + 1] = key;
		}
	}

	// Merge the blocks using an algorithm
	// similar to merge sort and initialize
	// the pointers to the beginning of each block
	vector<int> pointers(numBlocks);
	vector<int> result;
	while (true) {
		// Find the minimum element among the
		// active blocks
		int minVal = numeric_limits<int>::max();
		// minVal currently INT_MAX at start
		int minIdx = -1;
		for (int i = 0; i < numBlocks; i++) {
			if (pointers[i] < blocks[i].size()
				&& blocks[i][pointers[i]] < minVal) {
				minVal = blocks[i][pointers[i]];
				minIdx = i;
			}
		}
		// If all blocks are exhausted, we're done
		if (minIdx == -1) {
			break;
		}
		// Otherwise, add the minimum element
		// to the result and increment the
		// pointer for that block
		result.push_back(minVal);
		pointers[minIdx]++;
	}

	return result;
}

// Driver's code
int main()
{
	// Original Array
	vector<int> arr = { 7, 7, 4, 1, 5, 3, 2, 0 };
	cout << "Input : ";
	for (auto x : arr) {
		cout << x << " ";
	}
	cout << endl;

	// Printing result
	vector<int> result = grailSort(arr);
	cout << "Output: ";
	for (auto x : result) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}

