// cherryPickup.cpp


#include <bits/stdc++.h>
using namespace std;


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

*/


// brute force - gave tle
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



// memoization 

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

            // here in case if both robot are at same cell then add that cell contribution only once
            if (j1 == j2) return grid[i][j1];

            // dono jaha bhi khade h dono ka contribution count karo...
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }

        int maxi = -1e8;

        for (int dj1 = -1; dj1 <= 1; dj1++){
            for (int dj2 = -1; dj2 <= 1; dj2++){

                int value = 0;
                
                // if landed at same cell then add contribution once 
                if (j1 == j2) value += grid[i][j1];
                
                // if landed at different cell add both contributions..
                else value += grid[i][j1] + grid[i][j2];

                // now do it for next row .. moving in allowed columns...
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