// wiggleSorting2.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3] > nums[4] ......

You may assume the input array always has a valid answer.

// accha teen ka pair leke nahi sochna... less greater less greater wali inequality sochna h...


Example 1:

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]

Explanation: [1,4,1,5,1,6] is also accepted.

Example 2:

Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]
 

Constraints:

1 <= nums.length <= 5 * 1e4
0 <= nums[i] <= 5000

It is guaranteed that there will be an answer for the given input nums.
 

Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space? 

*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Step 1️⃣: Make a copy of the original array
        vector<int> nums1(nums);

        // Step 2️⃣: Sort the copy in increasing order
        sort(nums1.begin(), nums1.end());

        // Two pointers:
        // j -> start of the smaller half (low values)
        // k -> start of the larger half (high values)
        int j = (n - 1) / 2;  // middle or just before middle for odd n
        int k = n - 1;        // end of the array (largest element)

        // Step 3️⃣: Fill nums[] in a wiggle pattern from end to start
        // Why from end? Because if there are duplicates, placing largest last avoids conflicts.
        for (int i = 0; i < n; i++) {
            // Odd index (i % 2 == 1) should have larger element
            
            if (i % 2 == 0) {
                nums[i] = nums1[j];
                j--;
            } 
            
            else {
                nums[i] = nums1[k];
                k--;
            }
        }
    }
};
