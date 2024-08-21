#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        bool found = false;
        int maxi = INT_MIN;
        
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                if (nums[j] > nums[i]){
                    maxi = max(maxi, nums[j] - nums[i]);
                    found = true;
                }    
            }
        }

        if (!found) return -1;  // found == false
        else return maxi;
    }
};