#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

*/

class Solution {
public:
    int atMost(vector <int> &nums, int k){
        unordered_map <int,int> mp;
        int i=0, j=0, ans = 0;
        int n = nums.size();

        while (j<n){
            mp[nums[j]]++;  // increasing freq of nums[j]

            while (mp.size()>k && i<=j){
                mp[nums[i]]--;  // decreasing freq...or shrinking..
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;

    }




    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};


/*
dp, recursion, two pointer -> you should always start with middle values...

in general we increase j++ while (j<n)

also you need to figure out ki ans actually mai kaha compute ho raha hai...whether inside or outside while loop...

*/