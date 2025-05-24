// permutations2.cpp


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    void f(vector <int> &nums, vector <int> &v, vector <vector <int>> &permut, vector <int> &visited){
        
        if (v.size() == nums.size()){   // base case
            permut.push_back(v);
            return;
        }

        for (int i=0; i<nums.size(); i++){
            if (visited[i]) continue;

            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;

            visited[i] = 1;
            v.push_back(nums[i]);

            f(nums, v, permut, visited);

            visited[i] = 0;
            v.pop_back();
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // to avoid duplicates
        vector <int> v; // imp
        vector <vector <int>> permut;

        vector <int> visited(nums.size(), 0);

        f(nums, v, permut, visited);
        return permut;
    }
};




// using set
class Solution {
public:
    void solve(vector<int> &nums, set<vector<int>> &st, int idx) {
        // base case
        if (idx >= nums.size()) {
            st.insert(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);      // swap current index with i
            solve(nums, st, idx + 1);      // solve for next index
            swap(nums[idx], nums[i]);      // backtrack
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;               // use set instead of unordered_set
        solve(nums, st, 0);

        // transfer from set to vector
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


