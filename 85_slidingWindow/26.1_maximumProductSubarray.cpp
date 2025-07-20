// maximumProductSubarray

#include <bits/stdc++.h>
using namespace std;

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


    // ye to bhai ne ek universal fact wali baat kar di
    class Solution {
        public:
            int maxProduct(vector<int>& arr) {
                int pref = 1;
                int suff = 1;
                int ans = INT_MIN;
                int n = arr.size();
        
                for (int i=0; i<n; i++){
                    if (pref == 0) pref = 1;
                    if (suff == 0) suff = 1;
        
                    pref = pref * arr[i];
                    suff = suff * arr[n-i-1];
        
                    ans = max(ans, max(pref, suff));
                }
                return ans;
            }
};
        
        
        /*
        // prefix product nikala ... suffix product nikala ...un dono mai se jo bhi max hoga wahi answer hoga...
        */