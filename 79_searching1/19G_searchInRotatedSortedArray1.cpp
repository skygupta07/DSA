// searchInRotatedSortedArray1.cpp

/*

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k 
(1 <= k < nums.length) such that the resulting array is 
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).


For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, 
return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.


Example 1: {very good example given....}

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4


Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1


Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-10pow4 <= nums[i] <= 10pow4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10pow4 <= target <= 10pow4

*/

// searchInRotatedSortedArray1.cpp

/*
🔍 Problem Summary:

You are given an array 'nums' that is originally sorted in ascending order, 
but might have been rotated at some unknown pivot.

Example:
Original Sorted:       [0, 1, 2, 4, 5, 6, 7]
Possible Rotated:  →   [4, 5, 6, 7, 0, 1, 2]

Your task:
➡️ Given the rotated array and a target, return the index of the target.
➡️ Return -1 if the target is not found.
➡️ Must use O(log N) time complexity → Use Binary Search.

Constraints:
- 1 <= nums.length <= 5000
- -10^4 <= nums[i], target <= 10^4
- All elements in nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        // Binary Search loop → O(log N)
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // ✅ Case 1: Element found at mid
            if (nums[mid] == target) return mid;

            // 🔍 Step 2: Decide which half is sorted

            // 🟢 Case A: Left part [lo...mid] is sorted
            if (nums[lo] <= nums[mid]) {

                // ✅ Check if target lies in this sorted range
                if (target >= nums[lo] && target < nums[mid]) {
                    hi = mid - 1;  // search in left part
                } else {
                    lo = mid + 1;   // else search in right part
                }
            }

            // 🔵 Case B: Right part [mid...hi] is sorted
            else {

                // ✅ Check if target lies in this sorted range
                if (target > nums[mid] && target <= nums[hi]) {
                    lo = mid + 1;  // search in right part
                } else {
                    hi = mid - 1; // else search in left part
                }
            }
        }

        // ❌ If target not found in any range
        return -1;
    }
};



// O(N)
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        for (int i=0; i<arr.size(); i++){
            if (arr[i] == key) return i;
        }
        return -1;
    }
};