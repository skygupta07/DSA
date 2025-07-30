// minimumSizeSubarraySum 

#include <bits/stdc++.h>
using namespace std;


/*


Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray whose sum is greater than or equal to target. 
If there is no such subarray, return 0 instead.


Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2

Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1


Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 1e9
1 <= nums.length <= 1e5
1 <= nums[i] <= 1e4

*/

class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int left = 0;
        int sum = 0;

        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {

            sum += nums[right]; // Add the current element to the window.

            // Shrink the window while the sum is greater than or equal to the target.
            while (sum >= target) {
                minLen = min(minLen, right - left + 1); // Update the minimum length.
                
                sum -= nums[left]; // Remove the leftmost element from the window.
                left++; // Move the left pointer forward.
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen; // If no subarray found, return 0.
    }
};


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;    // will store the running sum of window .. dynamically right wale element ko add karenge and agar possible ho rha h to left se element ko nikalte bhi chalenge...
        
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++){
            // right wale element ko window mai include kiya...
            sum += nums[right];

            while (sum >= target){
                minLen = min(minLen, right - left + 1);    // back of the mind mai aap hi they
                sum -= nums[left]; // but aur acche ki taalash jaari thi...
                left++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};