//  maximumSumCircularSubarray.cpp

/*

Given a circular integer array nums of length n, 
return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. 
Formally, the next element of nums[i] is nums[(i + 1) % n] 
and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. 
Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], 
there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.


Example 1:

Input: nums = [1,-2,3,-2]
Output: 3

Explanation: Subarray [3] has maximum sum 3.

Example 2:

Input: nums = [5,-3,5]
Output: 10

Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Example 3:

Input: nums = [-3,-2,-3]
Output: -2

Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 1e4
-3 * 1e4 <= nums[i] <= 3 * 1e4

*/


#include <bits/stdc++.h>
using namespace std;

class Solution { // O(n^2) gives tle
public:

    int maxSubarraySumCircular(vector <int> &nums) {
        int n = nums.size();

        int maxSum = INT_MIN; // Initialize to the smallest possible value

        // Iterate through each starting point of the subarray
        for (int i = 0; i < n; i++) {
            int sum = 0; // Reset sum for the current starting point

            // Calculate the sum of all subarrays starting from index 'i'
            for (int j = 0; j < n; j++) {   // ha bhai 
                // Use modulo to handle the circular array wrapping
                sum += nums[(i + j) % n];   // akash

                // Update the maximum sum
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }

};


class Solution { // O(n)
public:

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the max subarray sum using Kadane's algorithm
        int maxSum = INT_MIN, currMax = 0;

        for (int num : nums) {
            currMax = max(currMax + num, num);
            maxSum = max(maxSum, currMax);
        }

        // Step 2: Find the min subarray sum using Kadane's algorithm
        int minSum = INT_MAX, currMin = 0, totalSum = 0;

        for (int num : nums) {
            currMin = min(currMin + num, num);
            minSum = min(minSum, currMin);

            totalSum += num;
        }

        // Step 3: Handle edge case where all elements are negative
        if (totalSum == minSum) return maxSum;

        // Step 4: Return the maximum of maxSum and (totalSum - minSum)
        return max(maxSum, totalSum - minSum);
    }
};
