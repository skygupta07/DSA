#include <bits/stdc++.h>
using namespace std;

/*

A wiggle sequence is a sequence where the differences between successive numbers strictly alternate 
between positive and negative. The first difference (if one exists) may be either positive or negative. 
A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3)
 alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. 
The first is not because its first two differences are positive, and the second is not because its last
 difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence,
 leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.


Example 1:

Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
Example 2:

Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).
Example 3:

Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2




*/

class Solution {
    public:
        int wiggleMaxLength(vector<int>& nums) {
            int n = nums.size();
            
            // Base case: If there is only one element, the max length is 1
            if (n <= 1) return n;
    
            // Two variables to track the longest sequence ending in a peak or valley
            int peak = 1;   // Max length when the last change was increasing
            int valley = 1; // Max length when the last change was decreasing
    
            // Iterate through the array to determine the wiggle sequence length
            for (int i = 1; i < n; i++) {
                if (nums[i] > nums[i - 1]) {  
                    // If current element is greater than previous, it forms a peak
                    peak = valley + 1;
                } 
                else if (nums[i] < nums[i - 1]) {  
                    // If current element is smaller than previous, it forms a valley
                    valley = peak + 1;
                }
            }
    
            // Return the maximum wiggle length
            return max(peak, valley);
        }
    };

    
    // method2
    
    class Solution {
        public:
            int wiggleMaxLength(vector<int>& nums) {
                int n = nums.size();
        
                // If there's only one element, the longest wiggle subsequence is 1
                if (n == 1) return 1;   
        
                int i = 0;
        
                // Skipping all consecutive equal elements from the beginning
                while ((i + 1) < n && nums[i] == nums[i + 1]) i++;
        
                // If the entire array consists of the same element, return 1
                if (i == n - 1) return 1;
        
                // Determine the initial trend: true for increasing, false for decreasing
                bool increasing = nums[i + 1] > nums[i];
        
                // Start the answer count from 2 since we have at least one valid wiggle
                int ans = 2;
        
                // Iterate through the rest of the array
                for (; i + 1 < n; i++) {
                    // If we were increasing and found a decrease, switch the trend
                    if (increasing && nums[i + 1] < nums[i]) {
                        increasing = false; // Now looking for an increase
                        ans++; // Count this as part of the wiggle sequence
                    }
                    // If we were decreasing and found an increase, switch the trend
                    if (!increasing && nums[i + 1] > nums[i]) {
                        increasing = true; // Now looking for a decrease
                        ans++; // Count this as part of the wiggle sequence
                    }
                }
        
                return ans;
            }
        };
        