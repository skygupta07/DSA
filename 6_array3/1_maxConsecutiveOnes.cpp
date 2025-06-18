#include <bits/stdc++.h>
using namespace std;

/*

Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. 
The maximum number of consecutive 1s is 3.


Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0; // Current count of consecutive 1's
        int maxCount = 0; // Maximum count of consecutive 1's encountered so far
        
        for (int i = 0; i < nums.size(); i++) { 

            if (nums[i] == 1) { // If the current element is 1
                count++; // Increment the current count
                maxCount = max(count, maxCount); // Update the maximum count if necessary
            } 
            
            else { 
                count = 0; // Reset the count when a 0 is encountered
            }
        }
        
        return maxCount; // Return the maximum count of consecutive 1's
    }
};


/*
The given code snippet is not an implementation of Kadane's Algorithm. 
However, it does follow a similar pattern of iterating through the array 
and maintaining a running count, but it is specifically tailored to finding 
the maximum number of consecutive 1s in a binary array.

Kadane's Algorithm is used to find the maximum sum of a contiguous subarray in an array of integers. 
It maintains a current sum and updates a global maximum sum as it iterates. 

This problem doesn't involve summing values, but rather counting consecutive 1s and 
resetting the count when encountering a 0

*/