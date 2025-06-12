// minimumFallingPathSum1.cpp

/*

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row 
that is either directly below or diagonally left/right. 
Specifically, the next element from position (row, col) will be 
(row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


Example 1:

Input: matrix = [[2,1,3],
                [6,5,4],
                [7,8,9]]

Output: 13
Explanation: There are two falling paths with a minimum sum as shown.


Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& matrix, int row, int col) {
        // boundary conditions
        if (col < 0 || col >= n) return INT_MAX;
        if (row == m - 1) return matrix[row][col];

        // memoization check
        if (dp[row][col] != INT_MAX) return dp[row][col];

        // recursive case
        int left = solve(matrix, row + 1, col - 1);
        int down = solve(matrix, row + 1, col);
        int right = solve(matrix, row + 1, col + 1);

        return dp[row][col] = matrix[row][col] + min({left, down, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, INT_MAX));

        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, solve(matrix, 0, j));
        }
        
        return mini;
    }
};
