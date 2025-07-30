// subarrayProductLessThanK.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers nums and an integer k, 
return the number of contiguous subarrays where the product of all the elements 
in the subarray is strictly less than k.

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8

Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:

Input: nums = [1,2,3], k = 0
Output: 0

*/

class Solution {
public:

        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            int n = nums.size();

            int i = 0, j = 0;   // Two pointers: i (left), j (right)
            
            int prod = 1;       // Stores the product of the current subarray
            
            int ans = 0;        // Stores the count of valid subarrays
    
            // Two-pointer (Sliding Window) approach
            while (j < n) {    // Step 1: Expand the window from the right side
                
                prod *= nums[j];  // Include nums[j] in the product
    
                // Shrink the window from the left if the product becomes >= k
                while (prod >= k && i <= j) {  
                    
                    prod /= nums[i]; // Remove nums[i] from the product
                    i++;             // Move the left pointer to shrink the window
                
                }
    
                // The number of valid subarrays ending at j is (j - i + 1)
                ans += (j - i + 1);
    
                j++;  // Move the right pointer to extend the window (Step 2)
            
            }
    
            return ans;

        }

    };
    


/*

while generating the subarray I will get the product simultaneously also...
to find subarray sum we calculated prefix sum...

valid range find kar liya then I know number of subarrays between i and j....
standard template 2 pointer ka yaad karo....

*/