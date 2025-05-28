// combinationSum1.cpp


/*
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target 
is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40



*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Ye function combinations generate karega using backtracking
    void solve(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int start) {
        // Agar target 0 ho gaya toh current combination valid hai
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Agar target negative ho gaya toh wapas return kar jao
        if (target < 0) return;

        // Har candidate ko explore karo starting from 'start' index
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]); // element add karo

            // Recursively call karo with updated target and same i (kyuki same element bar bar le sakte ho)
            solve(candidates, target - candidates[i], result, current, i);

            current.pop_back(); // backtrack karo
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector <int> current;

        solve(candidates, target, result, current, 0); // start index is 0 initially
        // agar index pass nahi kiya to duplicates answer aayenge...

        return result;
    }
};