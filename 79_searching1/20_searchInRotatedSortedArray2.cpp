// searchInRotatedSortedArray2.cpp


/*

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k 
(0 <= k < nums.length) such that the resulting array is 
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, 
return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.


Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true


Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-1e4 <= nums[i] <= 1e4
nums is guaranteed to be rotated at some pivot.
-1e4 <= target <= 1e4
 

Follow up: This problem is similar to Search in Rotated Sorted Array, 
but nums may contain duplicates. Would this affect the runtime complexity? How and why?

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector <int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) 
                return true;

            // Handle duplicates
            if (nums[lo] == nums[mid] && nums[hi] == nums[mid]) {
                lo++;
                hi--;
            }

            // First half is sorted
            else if (nums[lo] <= nums[mid]) {
                // Check if target lies within the sorted first half
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid - 1;
                } 
                
                else {
                    lo = mid + 1;
                }
            }

            // Second half is sorted
            else {
                // Check if target lies within the sorted second half
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1;
                } 
                
                else {
                    hi = mid - 1;
                }
            }

        }

        return false;

    }
};
