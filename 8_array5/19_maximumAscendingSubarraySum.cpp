// maximumAscendingSubarraySum.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array of positive integers nums, return the maximum possible sum of an 
strictly increasing subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

 
Example 1:

Input: nums = [10,20,30,5,10,50]
Output: 65

Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.


Example 2:

Input: nums = [10,20,30,40,50]
Output: 150

Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.


Example 3:

Input: nums = [12,17,15,13,10,11,12]
Output: 33

Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100


*/

class Solution {
public:

    // take help of ka da ne algo...
    int maxAscendingSum(vector <int> &nums) {
        int n = nums.size();

        if (n == 0) return 0; // Edge case: empty array
        
        int maxSum = nums[0];
        int currSum = nums[0]; 

        for (int i = 1; i < n; i++) {
            // Add to current ascending subarray sum
            if (nums[i] > nums[i - 1]) currSum += nums[i]; 

             // Reset for new ascending subarray
            else currSum = nums[i];
            
            maxSum = max(maxSum, currSum); // Update maxSum if needed
        }

        return maxSum;
    }
};
