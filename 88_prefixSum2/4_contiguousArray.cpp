// contiguousArray.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a binary array nums, return the maximum length of a contiguous subarray 
with an equal number of 0 and 1. 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1

*/


class Solution {
public:
    int findMaxLength (vector <int> &nums){
        int prefSum = 0;    // initially initialising with zero..
        int maxLen = 0;

        unordered_map <int,int> firstOcc{{0,-1}};

        for (int i=0; i<nums.size(); i++){
            prefSum += (nums[i] == 1) ? 1 : -1;

            if (firstOcc.count(prefSum)) maxLen = max(maxLen, i - firstOcc[prefSum]);
            else firstOcc[prefSum] = i;
        }
        return maxLen;
    }
};

/*

subarray by definition is contiguous
you can apply two pointer prefix sum sliding window here...

if you are given only two different characters
then you can track their occurences by simply assigning 0 and 1
using map to store the first occurence of specific character.....in prefix sum

*/

