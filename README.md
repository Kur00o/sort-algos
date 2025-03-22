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

