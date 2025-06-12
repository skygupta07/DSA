// partititonEqualSubsetSum.cpp


#include <bits/stdc++.h>
using namespace std;


/*

Given an integer array nums, return true if you can partition the array into two subsets 
such that the sum of the elements in both subsets is equal or false otherwise.
 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].


Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/



class Solution {
public:

    vector<vector<int>> dp;  // Memoization table: dp[idx][target] stores whether we can form 'target' sum from index idx onwards

    // Recursive function to check if a subset starting from index `idx` can sum up to `target`
    bool subsetSum(vector<int> &nums, int target, int idx) {
        // Base case: if target becomes 0, we found a valid subset
        if (target == 0) return true;

        // If we've reached the end of the array or target becomes negative, return false
        if (idx >= nums.size() || target < 0) return false;

        // Check memoization table to avoid recomputation
        if (dp[idx][target] != -1) return dp[idx][target];

        // Choice 1: Include the current number and move to next index
        // Choice 2: Skip the current number
        // If either leads to target sum, return true
        return dp[idx][target] = subsetSum(nums, target - nums[idx], idx + 1) || subsetSum(nums, target, idx + 1);
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        // Calculate the total sum of all elements
        for (auto num : nums) totalSum += num;

        // If the total sum is odd, it's impossible to split into two equal parts
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;  // Target sum for one of the subsets

        // Initialize the DP table with -1 (uncomputed)
        dp = vector<vector<int>>(nums.size(), vector<int>(target + 1, -1));

        // Start the recursive subset check from index 0
        return subsetSum(nums, target, 0);
    }
};


/*

Type	Complexity
⏱️ Time	O(n * sum/2) – Each state (idx, target) is computed once
💾 Space	O(n * sum/2) – For memoization table dp[n][sum/2]
n is the number of elements and sum is the total sum of the array.

*/

