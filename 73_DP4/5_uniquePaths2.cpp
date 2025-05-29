// uniquePaths2.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given an m x n integer array grid. 
There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. 
A path that the robot takes cannot include any square that is an obstacle.


Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.


Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.

There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

*/


class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // If the start or end is blocked, no path exists.
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;

        // DP table to store the number of ways to reach each cell.
        vector <vector <int>> dp(m, vector<int>(n, 0));

        // dp[i][j] will tell the number of ways to reach cell {i, j}


        // Initialize the start point.
        dp[0][0] = 1; // yes there is a only single way to reach the start point

        // Fill the DP table.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If the cell is an obstacle, there is zero way to reach it ...
                if (grid[i][j] == 1) dp[i][j] = 0;
                
                
                else {
                    // Add paths from the top and left cells if within bounds.
                    if (i > 0) dp[i][j] += dp[i-1][j];
                    if (j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }

        
        // The bottom-right cell contains the number of unique paths.
        return dp[m-1][n-1];
    }
};
