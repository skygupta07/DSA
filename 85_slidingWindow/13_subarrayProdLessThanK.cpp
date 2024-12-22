#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        int prod = 1;
        int ans = 0;

        // two pointers
        while (j<n){    // step 1 
            prod *= nums[j];

            // now trying to decrease the product..
            while (prod >= k && i<=j){
                prod /= nums[i];
                i++;
            }

            ans += j-i+1;
            j++;    // step 2
        }

        return ans;
    }
};


/*
while generating the subarray I will get the product simultaneously also...
to find subarray sum we calculated prefix sum...

valid range find kar liya then I know number of subarrays between i and j....
standard template 2 pointer ka yaad karo....

*/