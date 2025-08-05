// rangeSumQueryImmmutable.cpp


#include <bits/stdc++.h>
using namespace std;


/*

Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices 
left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]

Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 

Constraints:

1 <= nums.length <= 1e4
-1e5 <= nums[i] <= 1e5

0 <= left <= right < nums.length

At most 1e4 calls will be made to sumRange.

*/

// brute force
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


// interviews
class NumArray {
public:

    vector <int> pref;

    NumArray(vector <int> &nums) {
        
        int n = nums.size();
        pref.resize(n, 0);

        pref[0] = nums[0];

        for (int i=1; i<n; i++) pref[i] = nums[i] + pref[i-1];
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return pref[right];
        
        return pref[right] - pref[left - 1];
    }

};

