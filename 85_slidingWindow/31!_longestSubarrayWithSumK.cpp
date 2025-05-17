// longestSubarrayWithSumK.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array arr[] containing integers and an integer k, 
your task is to find the length of the longest subarray where the sum of its elements 
is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. 
The length of the longest subarray with a sum of 15 is 6.

Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.

Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].


Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
-109 ≤ k ≤ 109
*/

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        // Maps prefix sum to its earliest index
        unordered_map<int, int> prefixSumIndex; 

        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            // If the sum of the subarray from the start is equal to k
            if (prefixSum == k) {
                maxLen = i + 1; // Update max length to include the current index
            }

            // Check if there is a prefix sum such that removing it results in sum = k
            if (prefixSumIndex.find(prefixSum - k) != prefixSumIndex.end()) {
                maxLen = max(maxLen, i - prefixSumIndex[prefixSum - k]);
            }

            // Only store the first occurrence of each prefix sum
            if (prefixSumIndex.find(prefixSum) == prefixSumIndex.end()) {
                prefixSumIndex[prefixSum] = i;
            }
        }

        return maxLen;
    }
};


// prefixSum, twopointer, slidingwindow, map - frequently used datastructures in subarray questions