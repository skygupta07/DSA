// targetSum.cpp

/*

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols 
'+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 
and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.


Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5

Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3


Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to count subsets with sum = targetSum
    int countSubsets(vector <int> &nums, int targetSum) {
        int n = nums.size();

        // DP table: dp[i][j] = number of subsets using first i elements to get sum j
        vector <vector <int>> dp(n + 1, vector<int>(targetSum + 1, 0));

        // Base case: There is one subset (empty set) that makes sum = 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill the table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= targetSum; j++) {

                if (nums[i - 1] <= j) {
                    // Include or exclude current element
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } 
                
                else {
                    // Can't include current element
                    dp[i][j] = dp[i - 1][j];
                }

            }
        }

        return dp[n][targetSum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Check if (sum + target) is even and non-negative
        if (totalSum < abs(target) || (totalSum + target) % 2 != 0) {
            return 0;
        }

        int subsetSum = (totalSum + target) / 2;

        return countSubsets(nums, subsetSum);
    }
};
