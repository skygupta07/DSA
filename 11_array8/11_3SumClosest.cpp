// 3SumClosest

#include <bits/stdc++.h>
using namespace std;


/*

Given an integer array nums of length n and an integer target, 
find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104

*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort the array

        int closest = INT_MAX; // To store the closest sum
        int ans = 0;           // To store the result

        // Iterate over each number as the first element of the triplet
        for (int i = 0; i < n - 2; i++) {
            int lo = i + 1;     // Pointer to the next element
            int hi = n - 1;     // Pointer to the last element

            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi]; // current sum

                // Update the closest sum if this one is closer to the target - ye line badhiya h ekdum...
                if (abs(target - sum) < closest) {
                    closest = abs(target - sum);
                    ans = sum;
                }

                // Adjust pointers based on comparison with the target
                if (sum < target) {
                    lo++; // Increase the sum
                }
                else if (sum > target) {
                    hi--; // Decrease the sum
                }
                else {
                    return sum; // Exact match found
                }
            }
        }

        return ans;
    }
};

