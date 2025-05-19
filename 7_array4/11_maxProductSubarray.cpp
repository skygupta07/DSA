#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.


Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

*/


class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();

        int pref = 1;
        int suff = 1;

        int ans = INT_MIN; // globally maximize karega...
       
        for (int i=0; i<n; i++){
            // reset value if done wrong work...
            if (pref == 0) pref = 1;
            if (suff == 0) suff = 1;

            pref = pref * arr[i];
            suff = suff * arr[n-1-i];

            ans = max(ans, max(pref, suff));
        }

        return ans;
    }
};


/*
// prefix product nikala ... suffix product nikala ...
un dono mai se jo bhi max hoga wahi answer hoga...
*/