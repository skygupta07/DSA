// splitArrayLargestSum.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.


*/


class Solution {
    public:
        int splitArray(vector<int>& nums, int k) {
            // sabse bade element ka sum, jo minimum capacity hona chahiye (koi subarray isse zyada weight nahi le sakta)
            int minSum = *max_element(nums.begin(), nums.end());   // ==>> lo
            
            // total sum of all elements
            int totalSum = accumulate(nums.begin(), nums.end(), 0); // ==>> hi
    
            // jab tak minSum ko totalSum tak nahi le jaate
            while (minSum < totalSum) {
                // mid value calculate karte hain, jo possible capacity ho sakti hai
                int mid = minSum + (totalSum - minSum) / 2;
    
                // subarrays ka count, ek subarray count se shuru karte hain
                int count = 1;  // subarrayCount
                int currSum = 0; // current subarray ka total sum
    
                // har number ko dekhte hain
                for (int num : nums) {
                    // agar current subarray ka sum + current num mid se zyada ho gaya, toh naya subarray banana padega
                    if (currSum + num > mid) {
                        count++;   // ek aur subarray chahiye
                        currSum = 0; // nayi subarray se start karte hain
                    }
    
                    currSum += num; // current num ko current subarray ke sum mein add karte hain
                }
    
                // agar subarrays ka count k se zyada ho gaya, toh minSum ko increase karte hain
                if (count > k) {
                    minSum = mid + 1; // capacity ko badhate hain
                } else {
                    totalSum = mid;   // agar k subarrays ke andar fit ho sakte hain, toh total sum ko reduce karte hain
                }
            }
    
            // minSum return karte hain, jo minimized largest sum hai jo subarrays mein distribute ho sakta hai
            return minSum;
        }
    };
    