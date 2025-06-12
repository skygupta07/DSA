// cherryPickup2.cpp

/*

You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] 
represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).

Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).

When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
 

Example 1:


Input: grid = [[3,1,1],
              [2,5,1],
              [1,5,5],
              [2,1,1]]

Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.


Example 2:

Input: grid = [[1,0,0,0,0,0,1],
              [2,0,0,0,0,3,0],
              [2,0,9,0,0,0,0],
              [0,3,0,5,4,0,0],
              [1,0,2,3,0,0,6]]

Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.
 

Constraints:

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int m, n;

    int solve(vector <vector <int>> &grid, int i, int j1, int j2){
        // base cases
        if (i < 0 || i >= m || j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return -1e8;

        // if reached last row 
        if (i == m-1){
            // here in case if both robot are at same cell
            if (j1 == j2) return grid[i][j1];
            
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }

        int maxi = -1e8;

        for (int dj1 = -1; dj1 <= 1; dj1++){
            for (int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;

                if (j1 == j2) value += grid[i][j1];
                else value += grid[i][j1] + grid[i][j2];

                value += solve(grid, i+1, j1+dj1, j2+dj2);

                maxi = max(maxi, value);
            }   
        }

        return maxi;

    }


    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // only maintain i - coz both robot will remain in the same row...
        
        // grid, i, j1, j2
        return solve(grid, 0, 0, n-1);
    }
};



class Solution {
public:
    int m, n;

    vector <vector <vector <int>>> dp;


    int solve(vector <vector <int>> &grid, vector <vector <vector <int>>> &dp, int i, int j1, int j2){

        // base cases
        if (i < 0 || i >= m || j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return -1e8;

        // dp help
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        // if reached last row 
        if (i == m-1){
            // here in case if both robot are at same cell
            if (j1 == j2) return grid[i][j1];
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }

        int maxi = -1e8;

        for (int dj1 = -1; dj1 <= 1; dj1++){
            for (int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;

                if (j1 == j2) value += grid[i][j1];
                else value += grid[i][j1] + grid[i][j2];

                value += solve(grid, dp, i+1, j1+dj1, j2+dj2);

                maxi = max(maxi, value);
            }   
        }

        return dp[i][j1][j2] = maxi;

    }


    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // m * n * n ki 3d dp vector ...
        dp.assign(m, vector <vector <int>> (n, vector <int> (n, -1)));
        // only maintain i - coz both robot will remain in the same row...
        
        // grid, i, j1, j2
        return solve(grid, dp, 0, 0, n-1);
    }
};

