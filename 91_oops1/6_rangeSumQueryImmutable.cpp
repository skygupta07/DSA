#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

*/


class NumArray {
public:
    vector <int> v;

    NumArray(vector<int>& nums) {
        v = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for (int i=left; i<=right; i++) sum += v[i];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */