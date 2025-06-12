// houseRobber2.cpp

/*

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

 
Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), 
because they are adjacent houses.


Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.


Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Helper function to calculate maximum loot without circular dependency
    int helper(vector <int> &nums, int start, int end){
        int n = end - start + 1;

        if (n == 1) return nums[start]; // Ek hi ghar hai toh wahi loot lo

        vector <int> dp(n, 0);

        // Pehle ghar ka paisa le lo
        dp[0] = nums[start];  

        // Do ghar honge toh max choose karna padega
        dp[1] = max(nums[start], nums[start + 1]); 

        for (int i = 2; i < n; i++) {
            // nums[start + i] is very fascinating...
            dp[i] = max(dp[i - 1], nums[start + i] + dp[i - 2]);
        }

        return dp[n - 1]; // Maximum paisa return karna hai

    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Sirf ek ghar hai toh wahi le lo

        // Case 1: Pehla ghar lo, last nahi
        int option1 = helper(nums, 0, n - 2);

        // Case 2: Pehla nahi lo, last wala le sakte ho
        int option2 = helper(nums, 1, n - 1);

        return max(option1, option2); // Dono options ka max paisa return karo
    }
};
