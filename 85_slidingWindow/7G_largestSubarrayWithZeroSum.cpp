// largestSubarrayWithZeroSum.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array arr containing both positive and negative integers, 
the task is to compute the length of the largest subarray that has a sum of 0.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5

Explanation: The largest subarray with a sum of 0 is [-2, 2, -8, 1, 7].


Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.


Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation: The subarray is [0, -4, 3, 1, 0].

*/

class Solution {
public:

    int maxLen(vector <int> &arr) {
        int n = arr.size();
        
        unordered_map <int, int> prefixSumMap; // To store (sum, index)
        
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            
            sum += arr[i];

            // Subarray from 0 to i
            if (sum == 0) maxLen = i + 1; 
            

            if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                // If the sum was seen before, calculate the subarray length
                // yes this works (I have dry run) 
                // because if sum is repeated then the elements between the two sums will be 0
                
                maxLen = max(maxLen, i - prefixSumMap[sum]);
            } 

            else {
                // Store the first occurrence of this sum
                prefixSumMap[sum] = i;
            }
        }

        return maxLen;
    }

};