// triangle.cpp
// minimumPathSumInATriangularGrid.cpp

/*

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. 
More formally, if you are on index i on the current row, you may move to either 
index i or index i + 1 on the next row.
 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11

Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3

The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).


Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1

-10pow4 <= triangle[i][j] <= 10pow4
 

Follow up: Could you do this using only O(n) extra space, 
where n is the total number of rows in the triangle?

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // dp[row][idx] stores the minimum path sum from triangle[row][idx] to the bottom
    vector<vector<int>> dp;

    // Recursive helper function with memoization
    int solve(vector<vector<int>> &triangle, vector<vector<int>> &dp, int row, int idx) {
        int n = triangle.size();

        // Base case: if we are on the last row, return the value directly
        if (row == n - 1) return triangle[row][idx];

        // If already computed, return stored value
        if (dp[row][idx] != -1) return dp[row][idx];

        // Recursive call: explore downward and diagonal moves
        int down = solve(triangle, dp, row + 1, idx);       // Move straight down
        int diagonal = solve(triangle, dp, row + 1, idx + 1); // Move to the next column (diagonal)

        // Store and return the minimum path sum from current cell
        return dp[row][idx] = triangle[row][idx] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Initialize dp table with -1 for memoization
        dp.resize(n, vector<int>(n, -1));

        // Start from top of triangle (row 0, index 0)
        return solve(triangle, dp, 0, 0);
    }
};


/*
✅ Time Complexity: O(n²)

Each state dp[row][idx] is computed only once.
Total number of unique states in the triangle is roughly n(n+1)/2 ≈ O(n²).

✅ Space Complexity: O(n²) (for the dp table)

Recursion stack depth is O(n), and dp uses O(n²) space.

*/