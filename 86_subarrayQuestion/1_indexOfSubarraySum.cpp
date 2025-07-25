// indexOfSubarraySum.cpp


#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] containing only non-negative integers, 
your task is to find a continuous subarray (a contiguous sequence of elements) 
whose sum equals a specified value target. You need to return the 1-based indices 
of the leftmost and rightmost elements of this subarray. 
You need to find the first subarray whose sum is equal to the target.

Note: If no such array is possible then, return [-1].
*/


class Solution {
public:

    vector <int> subarraySum(vector <int> &arr, int target) {
        int n = arr.size();

        int left = 0;    // Marks the start of the current window
        int curr_sum = 0; // Stores the running sum of the current window

        for (int right = 0; right < n; right++) {
            // Add the current element to the running sum
            curr_sum += arr[right];

            // Shrink the window until the sum is less than or equal to the target
            while (curr_sum > target && left <= right) {
                curr_sum -= arr[left];
                left++;
            }

            // Check if the current window matches the target
            if (curr_sum == target) {
                return {left + 1, right + 1}; // Convert to 1-based indexing
            }
        }

        // If no subarray is found, return [-1]
        return {-1};
    }
};
