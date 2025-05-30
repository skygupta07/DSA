// find132Pattern

#include <bits/stdc++.h>
using namespace std;

/*

Given an array of n integers nums, a 132 pattern is a subsequence  {subarray bola hota to 
bahut hi jyada easily ho jaata} of three integers 

nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.


Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].


Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].


Constraints:

n == nums.length
1 <= n <= 2 * 10pow5
-10pow9 <= nums[i] <= 10pow9

*/


class Solution {
public:

    bool find132pattern(vector<int>& nums) {

        int n = nums.size();
        if (n < 3) return false; // 132 pattern ke liye kam se kam 3 elements toh chahiye hi

        // Yeh stack store karega possible nums[k] (jo middle se chhota hona chahiye, par left se bada)
        stack <int> stk; 

        int max_k = INT_MIN; // Yeh track karega ab tak ka best nums[k] 
        //  matlab 2nd element in "1 3 2" pattern

        // Right to left loop isliye kyunki hum nums[j] aur nums[k] ko identify karte hain pehle
        for (int j = n - 1; j >= 0; j--) {

            // Agar current nums[j] se chhota koi nums[i] mil gaya jo max_k se bhi chhota hai
            // Matlab 132 pattern mil gaya: nums[i] < nums[k] < nums[j]
            if (nums[j] < max_k) return true;

            // Jab tak stack ka top chhota hai nums[j] se — woh potential nums[k] ho sakta hai
            // Hum max_k ko update karte jaa rahe hain as we pop smaller elements
            
            while (!stk.empty() && stk.top() < nums[j]) {
                max_k = stk.top(); // Update max_k with the last popped (best candidate for 2 in "132")
                stk.pop();
            }

            // Har nums[j] ko stack mein daal do as a potential nums[j] for next iterations
            stk.push(nums[j]);
        }

        return false; // Agar loop khatam ho gayi and kuch pattern nahi mila, then return false
    }
};

