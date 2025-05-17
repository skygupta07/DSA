// singleNumber3.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums, in which exactly two elements appear only once 
and all the other elements appear exactly twice. Find the two elements that appear only once. 
You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:

Input: nums = [-1,0]
Output: [-1,0]

Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.

*/


class Solution {
public: 
    vector<int> singleNumber(vector <int> &nums){
        int firstXorSec = 0;
        // dusre jo bhi elements jo do bar repeat honge wo sab cancel ho jaenge...
        for (auto &num : nums) firstXorSec ^= num;

        int mask = 1;
        int first = 0;

        while (!(firstXorSec & mask)) mask <<= 1;

        for (auto &num : nums){
            if (num & mask) first ^= num;
        }

        return {first, firstXorSec ^ first};
    }
};



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector <int> ans;
        unordered_map <int ,int> freqMap;

        for (auto el : nums) freqMap[el]++;

        for (auto [el, freq] : freqMap){
            if (freq == 1) ans.push_back(el);
        }
        return ans;
    }
};