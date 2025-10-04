// countInversion.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104


*/

class Solution {
public:
    // Function to merge two halves and count inversions
    long long mergeAndCount(vector<int>& arr, int lo, int mid, int hi) {
        int n1 = mid - lo + 1;
        int n2 = hi - mid;

        vector <int> left(n1), right(n2);

        // Copy data to temp arrays
        for (int i = 0; i < n1; i++) left[i] = arr[lo + i];
        for (int j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = lo;

        long long invCount = 0;

        // Merge process
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } 
            
            else {
                arr[k++] = right[j++];
                // ✅ left[i] > right[j], so all remaining left[i..end] will be > right[j]
                invCount += (n1 - i);
            }
        }

        // Copy remaining elements
        while (i < n1) arr[k++] = left[i++];
        while (j < n2) arr[k++] = right[j++];

        return invCount;
    }

    // Recursive merge sort with inversion counting
    long long mergeSortAndCount(vector <int> &arr, int lo, int hi) {
        long long invCount = 0;

        if (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            // Left half inversions
            invCount += mergeSortAndCount(arr, lo, mid);

            // Right half inversions
            invCount += mergeSortAndCount(arr, mid + 1, hi);

            // Merge step inversions
            invCount += mergeAndCount(arr, lo, mid, hi);
        }

        return invCount;
    }

    // Main function
    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        return (int)mergeSortAndCount(arr, 0, n - 1);
    }
};
