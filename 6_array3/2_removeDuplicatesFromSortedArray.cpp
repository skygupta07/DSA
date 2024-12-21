#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        int n = nums.size();

        // idx ko bhi 1 and iterate bhi 1 se hi start kar dena...
        int idx = 1;
        for (int i=1; i<n; i++){
            if (nums[i] != nums[i-1]){
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx;
    }
};

/*
rattne wale algo h ye sab...
*/