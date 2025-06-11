// largestDivisibleSubset.cpp

/*

Given a set of distinct positive integers nums, 
return the largest subset answer such that every pair (answer[i], answer[j]) of elements 
in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.


Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.


Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();  
            
            // `maxi` stores the max length of the subset, `num` helps in backtracking
            int maxi = 1, num = -1; 

            // vector to store the largest divisible subset
            vector <int> v; 
    
            // Sort the numbers in ascending order to ensure that if nums[j] divides nums[i], then nums[j] < nums[i]
            sort(nums.begin(), nums.end());
    
            // DP array to store the maximum subset size ending at index i
            vector <int> dp(n, 1);
    
            // Step 1: Finding the length of the largest divisible subset
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    
                    // If nums[i] is divisible by nums[j] and it forms a larger subset than before
                    if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {

                        // Update the maximum subset size for index i
                        dp[i] = dp[j] + 1;
                        
                        // Update overall maximum subset length found
                        if (maxi < dp[i]) {
                            maxi = dp[i];
                        }

                    }
                }
            }
    
            // Step 2: Backtracking to reconstruct the largest divisible subset
            for (int i = n-1; i >= 0; i--) {

                // If current element is part of the largest subset and it maintains divisibility
                if (maxi == dp[i] && (num == -1 || num % nums[i] == 0)) {
                    
                    v.push_back(nums[i]);  // Add the element to the subset
                    
                    // Reduce the remaining size to track back the subset elements
                    maxi--;  
                
                    num = nums[i];  // Update the last added number to maintain divisibility
                }

            }
            return v;  // Return the largest divisible subset
        }
    };
    



