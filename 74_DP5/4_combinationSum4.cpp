// combinationSum4.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array of distinct integers nums and a target integer target, 
return the number of possible combinations {kind of permutation here...} that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0

*/


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // ✅ DP Array banana hai jisme dp[i] ka matlab:
        // "target sum i banane ke total tareeke using nums[] (order matters)"

        // vector<unsigned int> because values bada ho sakta hai — handle large counts
        vector <unsigned int> dp(target + 1, 0);

        // ✅ Base case:
        // Sum 0 banane ka sirf 1 tareeka hai — kuch bhi mat choose karo (empty set)
        // Naa kuch select karna bhi ek tareeka hi hai 😄
        dp[0] = 1;

        // ✅ Bottom-up DP fill karna start karo
        // i represents "current target sum" jise hum banane ki koshish kar rahe hain
        for (int i = 1; i <= target; i++) {

            // Har number ke liye check karo kya use karke current sum 'i' bana sakte ho
            for (int num : nums) {

                // Agar current number se subtract karne par valid (non-negative) sum bacha
                if (i - num >= 0) {

                    // Toh jitne tareeke se i-num ban sakta hai,
                    // utne hi naye tareeke i banane ke liye honge (by adding 'num' at the end)
                    dp[i] += dp[i - num];

                    // Example:
                    // Agar i = 4 aur num = 2
                    // Aur dp[2] = 3 (matlab 3 tareeke se 2 ban sakta hai)
                    // Toh 4 banane ke 3 naye tareeke honge: sabme 2 ko last me add karo
                }
            }
        }

        // ✅ Final answer: target sum banane ke total tareeke
        return dp[target];
    }
};
