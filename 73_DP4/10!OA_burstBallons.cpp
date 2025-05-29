// burstBallons.cpp - OA very Much Struggle

/*

You are given n balloons, indexed from 0 to n - 1.
Each balloon is painted with a number on it represented by an array nums.
You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins.
If i - 1 or i + 1 goes out of bounds of the array,
then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:

Input: nums = [1,5]
Output: 10

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxCoins(vector<int> &nums) {

        // Step 1: Add padding of 1 at the beginning and end of the array
        // Reason: when we burst a balloon at index `k`, we need to access its neighbors `i` and `j`.
        // To avoid out-of-bound issues and simplify calculations, we pad 1 at both ends.
        int n = nums.size() + 2; // original size + 2 for padding

        // Step 2: Create a padded array `v` initialized with 1s
        vector <int> v(n, 1);  // Initially: [1, 1, 1, ..., 1]
        
        // Copy original elements of nums into the middle of `v`
        int i = 1;

        for (auto num : nums) {
            v[i++] = num;
        }
        // Now `v` looks like: [1, nums[0], nums[1], ..., nums[n-1], 1]

        // Step 3: Create a 2D DP table
        // dp[i][j] represents the maximum coins obtained by bursting balloons between indices (i+1) to (j-1)
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Step 4: Start filling the dp table by considering subarrays of increasing length
        // len = length of current subarray (from i to j)

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                
                int j = i + len - 1; // j is the end index of the subarray

                // Step 5: Try bursting each balloon k between (i, j) as the *last* balloon in that subarray
                for (int k = i + 1; k < j; k++) {
                    
                    // Coins from bursting balloon `k` last in this subarray:
                    // v[i]*v[k]*v[j] because the balloons at i and j become neighbors of k after all others are burst
                    // dp[i][k] => coins collected from bursting all balloons between i and k (excluding k)
                    // dp[k][j] => coins collected from bursting all balloons between k and j (excluding k)

                    dp[i][j] = max(dp[i][j], 
                                   dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
                }
            }
        }

        // Step 6: The answer is in dp[0][n-1], which means bursting all balloons between 0 and n-1
        // i.e., full original array (excluding padding)
        return dp[0][n - 1];
    }
};
