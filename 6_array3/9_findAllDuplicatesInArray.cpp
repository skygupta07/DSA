#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums of length n where all the integers of nums are in the range 
[1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for (int i=0; i<nums.size(); i++){
            int idx = abs(nums[i]) - 1;
            nums[idx] *= -1;

            if ( nums[idx] > 0) ans.push_back(idx + 1);
        }
        return ans;
    }
};

/*
optimised solution 
1. scan every element in array.
2. negate the value at index of (absolute value of scanned element - 1 )
3. now check if the value which you negate -> if it is negative means you have encountered its first time ...
leave it .. but if it is positive => that it is a duplicate element....

*/