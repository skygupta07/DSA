// firstMissingPositive.cpp


/*

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.


Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.


Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.


Constraints:

1 <= nums.length <= 105
-2pow31 <= nums[i] <= 2pow31 - 1

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();

        // Step 1: Replace all non-positive numbers with a dummy value (n+1)
        // Why? Because our target range is only [1 ... n]
        // So values <= 0 or > n are irrelevant for our missing positive search
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }

        // ✅ Step 2: Use the indices as a hash map to mark presence of numbers
        // If a number `val` exists in [1, n], mark index (val-1) as negative
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);  // abs because values may be marked negative already

            if (val <= n && nums[val - 1] > 0) {
                // Mark nums[val - 1] as negative to indicate val is present
                nums[val - 1] *= -1;
            }
        }

        // ✅ Step 3: First index `i` with positive value => (i+1) is missing
        // This is because we never marked index i, meaning (i+1) doesn't exist in array
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        // ✅ Step 4: All numbers from 1 to n are present, so answer is n + 1
        return n + 1;
    }
};

/*
jab bhi [1,n] -> tak ki range mai hi elements milte hai to...wo index wala game karna hai...

We only need to keep track of which ones of the first n positive integers occur in the array.
To do this with no extra space, we can treat the array like a boolean array, 
where sign(arr[i]) indicates
whether the i-th positive integer is present or not. 

First, we replace all non-positive values with n + 1,
since we'll only use these indices as storage space. 

Then, for every one of the first n positive numbers in the
 array, we turn the value at their corresponding index negative. 
 
 Finally, all we need to do is check for the
 first positive value, which will give us the first missing positive. 
 
 If we find no such index, then all natural
  numbers up to n are present, so we return n + 1.

*/

//-----  method 2----------
class Solution {
public:

    int firstMissingPositive(vector<int> &nums) {
        
        // Step 1: Store all elements in a hash set for O(1) lookups
        unordered_set <int> st;

        for (auto el : nums) {
            st.insert(el);  // saare elements ko insert kar diya
        }

        // Step 2: Find the maximum element in the array
        // (used to define the upper limit of our search)
        int mx = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx) {
                mx = nums[i];  // maximum element track kar rahe hain
            }
        }

        // Step 3: Check from 1 to mx, the first missing positive number
        // i.e., pehla number jo set mein nahi hai, wahi missing hoga
        for (int num = 1; num < mx; num++) {
            if (st.find(num) == st.end()) {
                return num;  // pehla number jo nahi mila, wahi answer
            }
        }

        // Step 4: Handle edge cases
        // - If all numbers from 1 to mx are present, return mx + 1
        // - Also, if all numbers are <= 0 (i.e., mx <= 0), return 1

        return (mx + 1) <= 0 ? 1 : mx + 1;
    }

};


// set wala method...
// sort wala way...