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

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 5000
It is guaranteed that there will be an answer for the given input nums.
 

Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space? 

*/

class Solution {
    public:
        void wiggleSort(vector<int>& nums) {
            int n = nums.size();
            vector<int> nums1(nums);

            sort(nums1.begin(), nums1.end());

            int i = n-1;
            int j = 0;

            int k = i/2 + 1;
            
            while(i >= 0)
            {
                if(i % 2 == 1)
                {
                    nums[i] = nums1[k];
                    k++;
                }
                else
                {
                    nums[i] = nums1[j];
                    j++;
                }
                i--;
            }
        }
    };