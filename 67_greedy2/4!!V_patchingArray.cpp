// patchingArray.cpp

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
1 <= nums[i] <= 1e4

nums is sorted in ascending order.
1 <= n <= 2e31 - 1

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    int minPatches(vector <int> &nums, int n) {

        long patchesCount = 0;       // Number of patchesCount (i.e., extra numbers added to the array)
        long maxReach = 0;      // The maximum number we can form from 1 to maxReach using current array
        
        int i = 0; // Pointer for iterating through the input array `nums`
        int sz = nums.size(); 

        // Continue until we can form all numbers from 1 to n
        while (maxReach < n) {
            
            if (i < sz && nums[i] <= maxReach + 1) {
                // If nums[i] can be used to extend the range of formable numbers
                // Example: maxReach = 3, nums[i] = 4 → we can now reach up to 3+4 = 7
                maxReach += nums[i];
                
                i++;  // Move to next number in nums
            } 
            
            else {

                // If nums[i] is too large or no numbers left, we must add a patch
                // We add maxReach + 1, which is the smallest number we cannot form yet
                // This patch helps us extend the range from [1, maxReach] to [1, 2*maxReach + 1]
                patchesCount++;
                maxReach += maxReach + 1;

            }
        }

        return patchesCount;  // Return total number of patches added
    
    }
    
};

