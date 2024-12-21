#include <bits/stdc++.h>
using namespace std;

/* // LC 41 hard
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++) if (nums[i] <= 0) nums[i] = n + 1;
        
        for (int i=0; i<n; i++) if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        
        for (int i=0; i<n; i++) if (nums[i]>0) return i+1;

        return n+1;
     }
};


/*
jab bhi [1,n] -> tak ki range mai hi elements milte hai to...wo index wala game karna hai...

We only need to keep track of which ones of the first n positive integers occur in the array. 
To do this with no extra space, we can treat the array like a boolean array, where sign(arr[i]) indicates
whether the i-th positive integer is present or not. First, we replace all non-positive values with n + 1, 
since we'll only use these indices as storage space. Then, for every one of the first n positive numbers in the
 array, we turn the value at their corresponding index negative. Finally, all we need to do is check for the 
 first positive value, which will give us the first missing positive. If we find no such index, then all natural
  numbers up to n are present, so we return n + 1.

*/




//-----  method 2----------


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set <int> st;
        for (auto el : nums) st.insert(el);

        // finding max element of array....
        int mx = INT_MIN;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] > mx) mx = nums[i];
        }

        for (int i=1; i<mx; i++){
            if (st.find(i) == st.end()) return i;
        }
        
        return  (mx + 1 ) <= 0 ? 1 : mx+1 ;
    }
};


// set wala method...
// sort wala way...