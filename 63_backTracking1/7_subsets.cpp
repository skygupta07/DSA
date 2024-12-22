#include <bits/stdc++.h>
using namespace std;

// inclusion and exclusion principle...

class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>> &ans,vector <int> &sub, int idx ){
        ans.push_back(sub);

        for (int j=idx; j<nums.size(); j++){
            sub.push_back(nums[j]);
            helper(nums, ans, sub, j+1);
            sub.pop_back();
        }

    }



vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> sub;

        helper(nums,ans,sub,0);
        return ans;
    }
};



// bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int p = 1<<n;

        vector<vector<int>> subs(p);

        for (int i=0; i<p; i++){
            for (int j=0; j<n; j++){
                if ((i>>j)&1) subs[i].push_back(nums[j]);
            }
        }
        return subs;
    }
};