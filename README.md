# sort-algos
===========================================================================

Counting Sort:

Declare an auxiliary array countArray[] of size max(inputArray[])+1 and initialize it with 0.
Traverse array inputArray[] and map each element of inputArray[] as an index of countArray[] array, i.e., execute countArray[inputArray[i]]++ for 0 <= i < N.
Calculate the prefix sum at every index of array inputArray[].
Create an array outputArray[] of size N.
Traverse array inputArray[] from end and update outputArray[ countArray[ inputArray[i] ] – 1] = inputArray[i]. Also, update countArray[ inputArray[i] ] = countArray[ inputArray[i] ]- – .

===========================================================================

Bitonic Sort:

Bitonic sequence is created.
Comparison between the corresponding element of the bitonic sequence.
Swapping the second element of the sequence.
Swapping the adjacent element.
It mainly involves two steps.  

Form a bitonic sequence (discussed above in detail). After this step we reach the fourth stage in the below diagram, i.e., the array becomes {3, 4, 7, 8, 6, 5, 2, 1}
Creating one sorted sequence from a bitonic sequence: After the r first state ep, the first half is sorted in increasing order and the second half in decreasing order. 
We compare the first element of the first half with the first element of the second half, then the second element of the first half with the second element of the second, and so on. We exchange elements if an element of the first half is larger than second half. 
After her above compare and exchange steps, we get two bitonic sequences in the array. See the fifth stage below the diagram. In the fifth stage, we have {3, 4, 2, 1, 6, 5, 7, 8}. If we take a closer look at the elements, we can notice that there are two bitonic sequences of length n/2 such that all elements in the first bitonic sequence {3, 4, 2, 1} are smaller than all elements of the second bitonic sequence {6, 5, 7, 8}. 
We repeat the same process within two bitonic sequences and we get four bitonic sequences of length n/4 such that all elements of the leftmost bitonic sequence are smaller and all elements of the rightmost. See sixth stage in below diagram, arrays is {2, 1, 3, 4, 6, 5, 7, 8}. 
If we repeat this process one more time we get 8 bitonic sequences of size n/8 which is 1. Since all these bitonic sequences are sorted and every bitonic sequence has one element, we get the sorted array.

===========================================================================

Grail Sort:

Divide the input array into blocks of size sqrt(n), where n is the length of the input array.
Sort each block using a comparison-based sorting algorithm.
Merge the sorted blocks into a single sorted array using an algorithm similar to merge sort.
Repeat steps 2 and 3 until all blocks have been merged into a single sorted array.

===========================================================================

Pancake Sort:

Start from current size equal to n and reduce current size by one while it’s greater than 1. Let the current size be curr_size. 
Do following for every curr_size
Find index of the maximum element in arr[0 to curr_szie-1]. Let the index be ‘mi’
Call flip(arr, mi)
Call flip(arr, curr_size – 1)

===========================================================================

Radix Sort:

The key idea behind Radix Sort is to exploit the concept of place value. It assumes that sorting numbers digit by digit will eventually result in a fully sorted list. Radix Sort can be performed using different variations, such as Least Significant Digit (LSD) Radix Sort or Most Significant Digit (MSD) Radix Sort.

===========================================================================

Spaghetti Sort:

Simulate the lengths of the elements using spaghetti sticks or analogous representations. Each stick represents a number. Drop the spaghetti sticks vertically against a surface where they stand on one end. The longest stick (the most significant number) will stand tallest. Read the sticks from top to bottom to get a sorted array in descending order. For ascending order, reverse the process. This sort is more of a conceptual or physical sort and is not efficient for large digital datasets.

===========================================================================

Splaysort:

Splaysort is based on the splay tree, a self-adjusting binary search tree. Insert all elements into a splay tree one by one. After every insertion, the inserted node is splayed to the root. Once all insertions are complete, perform an in-order traversal of the tree to retrieve the sorted sequence. It maintains adaptive performance on partially sorted data.

===========================================================================

Symmetric Compare Sort:

Symmetric Compare Sort uses a recursive, symmetric comparison strategy. The array is divided symmetrically, and pairs of elements equidistant from the center are compared and potentially swapped. These comparisons are recursively applied to subarrays in a mirrored way. This sort maintains a balance of comparisons similar to bitonic sorting, useful for parallel processing.

===========================================================================

3-Way Merge Sort:

The input array is divided into three equal parts instead of two (as in traditional merge sort). Recursively sort each of the three parts. Merge the three sorted parts using a 3-way merging process where the smallest of the front elements of each part is selected iteratively. This reduces recursion depth and can improve performance for specific data distributions.

===========================================================================

Factorial Sort:

Factorial Sort is a theoretical sort that uses the concept of Lehmer codes and permutation indexes. For an array of length n, the position of each element in the sorted array is encoded using its factorial number system representation. Decode these positions to reconstruct the sorted array. Due to factorial time complexity (O(n!)), this sort is mostly academic and impractical for large datasets.

===========================================================================
