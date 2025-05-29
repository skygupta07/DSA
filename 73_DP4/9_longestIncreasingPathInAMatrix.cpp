#include <bits/stdc++.h>
using namespace std;


/*

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).


Example 1:

Input: matrix = [[9,9,4],
                [6,6,8],
                [2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].


Example 2:

Input: matrix = [[3,4,5],
                [3,2,6],
                [2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.


Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1

*/

class Solution {
public:

    // DFS function to compute longest increasing path starting from cell (i, j)
    int dfs(vector <vector <int>> &matrix, vector<vector<int>> &dp, int i, int j) {
        int m = matrix.size();        // Total number of rows
        int n = matrix[0].size();     // Total number of columns

        // If already computed, return the stored result to avoid recomputation
        if (dp[i][j] != -1) return dp[i][j];

        // Direction vectors: up, right, down, left (clockwise)
        int dx[] = {-1, 0, 1, 0};     // Row offsets
        int dy[] = {0, 1, 0, -1};     // Column offsets

        int maxLen = 1;  // At minimum, the path consists of the current cell itself

        // Explore all 4 directions
        for (int dir = 0; dir < 4; dir++) {
            
            int ni = i + dx[dir];     // New row index
            int nj = j + dy[dir];     // New column index

            // Check if (ni, nj) is within bounds and strictly increasing
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                // Recursive DFS call for the next valid increasing cell
                maxLen = max(maxLen, 1 + dfs(matrix, dp, ni, nj));
            }
            
        }

        // Memoize and return the result for cell (i, j)
        return dp[i][j] = maxLen;
    }

    // Main function to find the longest increasing path in the matrix
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();         // Number of rows
        int n = matrix[0].size();      // Number of columns

        // DP table initialized with -1 (unvisited)
        vector <vector <int>> dp(m, vector<int> (n, -1));

        int maxLen = 0; // Variable to keep track of global max length

        // Try to start DFS from every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Start a DFS from (i,j) and update the global max length
                maxLen = max(maxLen, dfs(matrix, dp, i, j));
            }
        }

        return maxLen; // Final answer: maximum of all starting points
    }
};

