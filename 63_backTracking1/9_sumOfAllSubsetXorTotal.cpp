#include <bits/stdc++.h>
using namespace std;

/*
The XOR total of an array is defined as the bitwise XOR of all its elements,
 or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by 
deleting some (possibly zero) elements of b.
*/

class Solution {
public:
    int subset(vector <int> &nums, vector <int> &sub, int idx){
        // kisi bhi tarah ki call ho base case to issi condition pe hit karega...
        if ( idx == nums.size() ){
            int xorr = 0;
            for (int i=0; i<sub.size(); i++) xorr ^= sub[i];
            return xorr;
        }
        
        // include the current element
        sub.push_back(nums[idx]);
        int include = subset(nums,sub,idx+1);
        // ek baar hata ke call lagai....
        sub.pop_back();

        int exclude = subset(nums,sub,idx+1);

        // return the sum of both choices..
        return include + exclude;
    }


    int subsetXORSum(vector<int>& nums) {
        vector <int> sub;
        return subset(nums,sub,0);
    }
};