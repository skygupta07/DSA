#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &sub, int currIdx) {
        int n = nums.size();
        
        // Base case: if current index is out of bounds, add the subset to the answer and return(mai bhul jaata hu)
        if (currIdx == n) {
            ans.push_back(sub);
            return;
        }
        
        // Include the current element
        sub.push_back(nums[currIdx]);
        helper(nums, ans, sub, currIdx + 1);
        sub.pop_back(); // Backtrack
        
        // Skip duplicates -> bas ab yaha ye hi to extra tha...
        while (currIdx <= n-2 && nums[currIdx] == nums[currIdx + 1]) {
            currIdx++;
        }

        // Exclude the current element
        helper(nums, ans, sub, currIdx + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        helper(nums, ans, sub, 0);
        return ans;
    }
};
