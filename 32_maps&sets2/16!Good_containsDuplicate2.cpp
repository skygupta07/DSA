#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums and an integer k, 
return true if there are two distinct indices i and j in the array 
such that nums[i] == nums[j] and abs(i - j) <= k.

 
Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true


Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true


Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 1pow05
-10pow9 <= nums[i] <= 10pow9
0 <= k <= 10pow5


*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int,int> mp;
        
        for(int i=0; i<n; i++){

            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if(mp.count(nums[i])){
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if(abs(i-mp[nums[i]])<=k) return true;
            }
            // if I have seen or not seen this number before, insert the number (as key) with its index as (value) in the map...
            // and if the number is already present in the map, then update the position of that number
            mp[nums[i]] = i;
        }
        // after the complete traversal, if we don't find a pair to satisfy the condition, return false
        return false;
    }
};