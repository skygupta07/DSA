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


Example 1:

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


// log(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1;

        // Binary Search loop
        while (low <= high) {
            // Avoid overflow (better than (low + high)/2)
            int mid = low + (high - low) / 2;

            // Case 1: If key found at mid
            if (arr[mid] == key) return mid;

            // Step 2: Decide which part is sorted

            // Left half is sorted
            if (arr[low] <= arr[mid]) {
                // Check if key lies within the left sorted half
                if (key >= arr[low] && key < arr[mid]) {
                    high = mid - 1;  // Search in left half
                } else {
                    low = mid + 1;   // Search in right half
                }
            } 
            
            // Right half is sorted
            else {
                // Check if key lies within the right sorted half
                if (key > arr[mid] && key <= arr[high]) {
                    low = mid + 1;   // Search in right half
                } else {
                    high = mid - 1;  // Search in left half
                }
            }
        }

        // If we exit the loop, key is not found
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