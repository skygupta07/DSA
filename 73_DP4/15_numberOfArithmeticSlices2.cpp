// numberOfArithmeticSlices2.cpp
#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements 
and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed
by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.

*/

class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& nums) {
            int n = nums.size();
            int totalCount = 0; // Total arithmetic subsequences count store karne ke liye variable
    
            // Har index pe ek unordered_map rakhenge jo diff ke corresponding subsequence count store karega
            vector <unordered_map <long long, int >> dp(n);
    
            // Outer loop jo har index i ke liye kaam karega
            for (int i = 1; i < n; i++) {
                // Inner loop jo har index j (0 se i-1 tak) ke liye kaam karega
    
                for (int j = 0; j < i; j++) {
                    
                    long long diff = (long long) nums[i] - nums[j]; // Difference calculate kiya nums[i] aur nums[j] ka
    
                    // Agar diff INT_MIN ya INT_MAX ke bahar chala jaye to ignore karo (overflow handle karne ke liye)
                    if (diff < INT_MIN || diff > INT_MAX) continue;
    
                    // Agar diff pehle se exist karta hai dp[j] me, to uska count le lo, nahi to 0 assign karo
                    int count = dp[j].count(diff) ? dp[j][diff] : 0;
    
                    // Jo valid arithmetic subsequences mil rahe hain unko totalCount me add karo
                    totalCount += count;
    
                    // dp[i][diff] me naye subsequences add karo (count + 1 kyunki ek naya pair (j, i) bana hai)
                    dp[i][diff] += count + 1;
                }
            }   
    
            return totalCount; // Final count return karo
        }
    };
    