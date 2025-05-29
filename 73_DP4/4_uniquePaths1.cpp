#include <bits/stdc++.h>
using namespace std;

/*


There is a robot on an m x n grid. 
The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take 
to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10pow9.
 

Example 1:

Input: m = 3, n = 7
Output: 28


Example 2:

Input: m = 3, n = 2
Output: 3


Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100

*/


class Solution {    // brute force gives tle
public:

    int f(int i, int j){
        // base case 
        if (i==0 && j==0) return 1;

        if (i<0 || j<0) return 0;

        int up = f(i-1, j);
        int left = f(i, j-1);

        return up + left;
    }


    int uniquePaths(int m, int n) {
        // yrr yaha ulta sochna kucch jyada hi help kar rha h ...
        // source se destination ❌, destination se source ka socho ✅

        return f(m-1, n-1);
    }
};


/*

jab dp lagegi to obviously m * n size ki lagegi... 
kyuki tabhi to m-1 and n-1 wala index possible ho paega....

*/



class Solution { // Using Memoization (Top-Down DP)
public:

    // Helper recursive function to compute number of unique paths from (0,0) to (i,j)
    int f(vector<vector<int>> &dp, int i, int j) {
        // Base Case 1: If we reach the starting cell (0,0), it means there's one valid path
        if (i == 0 && j == 0) return 1;

        // Base Case 2: If indices go out of bounds, it's not a valid path
        if (i < 0 || j < 0) return 0;

        // If the value is already computed (i.e., not -1), return the cached result
        if (dp[i][j] != -1) return dp[i][j];

        // Recursively calculate number of paths coming from top and left
        int up = f(dp, i - 1, j);      // Move from the cell above (i-1, j)
        int left = f(dp, i, j - 1);    // Move from the cell to the left (i, j-1)

        // Store the result in dp[i][j] and return it
        return dp[i][j] = up + left;
    }

    // Main function to be called with grid size m x n
    int uniquePaths(int m, int n) {
        // Create a 2D DP table of size m x n, initialized with -1
        // dp[i][j] will store the number of unique paths from (0,0) to (i,j)
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Start the recursion from the destination cell (m-1, n-1)
        return f(dp, m - 1, n - 1);
    }

};



/*
memoization approach ...
jab dp lagegi to obviously m * n size ki lagegi... 
kyuki tabhi to m-1 and n-1 wala index possible ho paega....

*/


class Solution {    // tabulation
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize the first row and first column to 1, since there's only one way to reach any cell in the first row or column
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        
        // Fill the rest of the dp table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        // The bottom-right cell will contain the number of unique paths
        return dp[m-1][n-1];
    }
};