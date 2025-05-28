#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums that may contain duplicates, 
return all possible subsets (the power set).

The solution set must not contain duplicate subsets. 
Return the solution in any order.


Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]


Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10

*/

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
        vector <vector <int>> ans;
        vector <int> sub;
        
        // Sort to handle duplicates
        sort(nums.begin(), nums.end()); 

        helper(nums, ans, sub, 0);
        
        return ans;
    }
};
