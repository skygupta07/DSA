// maximumSumOfDistinctSubarraysWithLengthK.cpp

/*

You are given an integer array nums and an integer k.
Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. 
If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 
Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15

Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions


Example 2:

Input: nums = [4,4,4], k = 3
Output: 0

Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

        long long maximumSubarraySum(vector <int> &nums, int k) {
            int n = nums.size();

            if (k > n) return 0; // Edge case: k is larger than the array size.
    
            unordered_set <int> st; // Set to track unique elements in the window.
            
            long long sum = 0;     // Current subarray sum.
            long long maxi = 0;    // Maximum sum of valid subarray.
    
            int left = 0; // Start of the sliding window.
    
            for (int right = 0; right < n; right++) { // End of the sliding window.
                
                while (st.count(nums[right])) {
                    // Remove elements from the start of the window until nums[j] can be added.
                    sum -= nums[left];
                    st.erase(nums[left]);
                    left++;
                }
    
                // Add the current element to the window.
                st.insert(nums[right]);
                sum += nums[right];
    
                // Check if the current window is of size k and update maximum sum.
                if (right - left + 1 == k) maxi = max(maxi, sum);
            
            }
    
            return maxi;
        }
    };
    

// brute force approach -> gives TLE
class Solution {  
public:

        bool distinctSubarray(vector <int> &nums, int i, int j, int k){
            unordered_set <int> st;

            for (int it = i; it<=j; it++){
                st.insert(nums[it]);
            }

            return (st.size() == k); // tumhare haramipan ke ....
        }
    
        long long subarraySum(vector <int> &nums, int i, int j){
            long long sum = 0;

            for (int it=i; it<=j; it++) sum += nums[it];

            return sum;
        }
    
    
        long long maximumSubarraySum(vector<int>& nums, int k) {
            int n = nums.size();
    
            if (k > n) return 0;
    
            int i = 0;
            int j = k-1;
            
            long long maxi = 0;
    
            while (j < n){
                if (distinctSubarray(nums, i, j, k)){
                    maxi = max(maxi, subarraySum(nums, i, j));
                }

                i++;
                j++;
            }
    
            return maxi;
        }
};
        