// combinationSum2.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.


Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
]


Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 

[
    [1,2,2],
    [5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30


*/



class Solution {
public:
    // curr ko reference se pass kiya for better performance
    void solve(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& curr, int idx) {
        // base case: agar target 0 hai, to valid combination mil gaya
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        if (target < 0) return; // invalid path

        for (int i = idx; i < candidates.size(); i++) {
            // same recursive level mein duplicates skip karo
            if (i > idx && candidates[i] == candidates[i - 1]) continue;

            curr.push_back(candidates[i]);

            // i+1 because element ek hi baar use kar sakte ho
            solve(candidates, target - candidates[i], result, curr, i + 1);

            curr.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        sort(candidates.begin(), candidates.end()); // duplicates ko handle karne ke liye

        solve(candidates, target, result, curr, 0);

        return result;
    }
};
