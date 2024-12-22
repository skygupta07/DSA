#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        int mx = INT_MIN;
        int freq = 0;

        for (int i=0; i<n; i++){
            if (nums[i] > mx) mx = nums[i];
        }

        long long ans = 0;

        while (j<n){
            if (nums[j] == mx) freq++;

            while (freq >= k){
                ans += n-j;     // addding the subarrays contribution..
                if (nums[i] == mx) freq--;
                i++;
            }
            j++;
        }

        return ans;
    }
};