#include <bits/stdc++.h>
using namespace std;


/*

Given a sorted integer array nums and an integer n, 
add/patch elements to the array such that any number in the range [1, n] 
inclusive can be formed by the sum of some elements in the array.

Return the minimum number of patches required.

Example 1:

Input: nums = [1,3], n = 6
Output: 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.


Example 2:

Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].


Example 3:

Input: nums = [1,2,2], n = 5
Output: 0
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
nums is sorted in ascending order.
1 <= n <= 2pow31 - 1

*/
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long patches = 0;       // Number of patches (numbers added)
        long maxReach = 0;      // Maximum number we can form using current nums and patches
        
        int i = 0;              // Pointer to iterate through the nums array
        int sz = nums.size(); 

        // Keep adding patches until we can form all numbers from 1 to n
        while (maxReach < n) {
            
            if (i < sz && nums[i] <= maxReach + 1) {
                // If current number can extend the current range
                maxReach += nums[i];
                i++;
            } 
            
            else {
                // Patch is required: add maxReach + 1
                // This patch allows us to form numbers up to 2*maxReach + 1
                patches++;
                maxReach += maxReach + 1;
            }
        }

        return patches;
    }
};
