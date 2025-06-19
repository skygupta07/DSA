// increasingTripletSubsequence.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums, return true if there exists a triple of indices (i, j, k) 
such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.


Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.


Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 
Constraints:

1 <= nums.length <= 5 * 105
-2pow31 <= nums[i] <= 2pow31 - 1
 

Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?

*/

class Solution { // wrong code
public: 
    bool increasingTriplet(vector <int> &nums){

        // Initialize first and second to maximum possible value
        int first = INT_MAX;
        int second = INT_MAX; 
        
        for (int num : nums) {

            // inequality nahi chalegi...(num <= first) this will handle repetition
            // Update the smallest number

            if (num < first) first = num; 
            
            else if (num < second) second = num; // Update the second smallest number
            
            // If we find a number greater than both first and second, we found a triplet
            else return true;
        
        }

        // No triplet found
        return false; 
    }
};


/*
Wrong Answer
44 / 84 testcases passed


Editorial
Input
nums =
[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]

View less

Use Testcase
Output
true
Expected
false

*/


class Solution {    // correct 
public:

    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        
        // it is a kind of pure DSA, I have dry run and verified the code, you just need to 
        // remember the code roughly....
        
        for (int i=0; i<nums.size(); i++){
            if (nums[i] <= first) first = nums[i];

            else if (nums[i] <= second) second = nums[i];

            else return true;
        }

        return false;
    }
};