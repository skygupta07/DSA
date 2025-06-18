// maximumProductSubarray.cpp

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

1 <= nums.length <= 2*1e4
-10 <= nums[i] <= 10

The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

*/


// brute force subarray two loops
class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;
        
        for (int i=0; i<n; i++){
            int prod = 1;

            for (int j=i; j<n; j++){
                prod = prod * nums[j];
                maxProd = max(maxProd, prod);
            }
        }

        return maxProd;
 
    }
};


/*
A subarray is a contiguous non-empty sequence of elements within an array

brute force -> generate all subarray find its product ... simultaneously update the maximum product subarray found
till now....   finally return the max. product...
*/

class Solution {
public:

    int maxProduct(vector<int>& arr) {
        int n = arr.size();

        int pref = 1;  // ➤ prefix product from left
        int suff = 1;  // ➤ suffix product from right

        int maxi = INT_MIN; // ➤ global maximum (init with lowest possible)

        // ➤ Loop through the array once from both ends
        for (int i = 0; i < n; i++) {
            
            // Step 1: Reset the product to 1 if a zero is encountered
            // ➤ Because product becomes 0 and should not affect future values
            if (pref == 0) pref = 1;
            if (suff == 0) suff = 1;

            // Step 2: Multiply current element from the front
            pref = pref * arr[i];

            // Step 3: Multiply current element from the back
            suff = suff * arr[n - 1 - i];

            // ✅ Step 4: Update the maxi with the best seen so far
            // ➤ It could be from prefix or suffix
            maxi = max(maxi, max(pref, suff));
        }

        return maxi;
    }
};


/*
// prefix product nikala ... suffix product nikala ...
un dono mai se jo bhi max hoga wahi answer hoga...
*/