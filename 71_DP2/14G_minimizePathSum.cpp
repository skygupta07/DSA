// minimizePathSum.cpp

/*

Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.


Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

*/

// Leads to exponential time complexity: O(2^(m+n)) in the worst case.

#include <bits/stdc++.h>
using namespace std;

class Solution { // Brute-force recursive approach
public:
    int m, n;

    // Recursive function to find min path sum to cell (i, j)
    long long f(vector<vector<int>> &grid, int i, int j) {
        // Base case: reached the starting cell
        if (i == 0 && j == 0) {
            return grid[0][0];
        }

        // Out of bounds: return a large value (invalid path)
        if (i < 0 || j < 0) return INT_MAX;

        // Recursive calls: move from left or from top
        long long left = grid[i][j] + f(grid, i, j - 1);     // Move left
        long long up   = grid[i][j] + f(grid, i - 1, j);     // Move up

        // Return the minimum path sum to cell (i, j)
        return min(left, up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Start recursion from bottom-right corner
        return f(grid, m - 1, n - 1);
    }

};



class Solution {    // memoization
public:
    int m, n;

    long long f(vector <vector <int> > &grid, vector <vector <long long>> &dp,  int i, int j){

        if (i == 0 && j == 0){
            return grid[0][0];
        }

        if (i<0 || j<0) return INT_MAX;

        if (dp[i][j] != -1) return dp[i][j];

        long long left = grid[i][j] + f(grid, dp, i, j-1);
        long long up = grid[i][j] + f(grid, dp, i-1, j);

        return dp[i][j] = min(left, up);
    }

    int minPathSum(vector <vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();

        vector <vector <long long> > dp(m, vector <long long>(n, -1));

        return f(grid, dp, m-1, n-1);
    }
};


class Solution {    // tabulation
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        vector <vector <int>> dp(m, vector <int> (n, -1));
        
        // high threshold 
        dp[0][0] = grid[0][0];

        // filling first row.. => iterator ka to col vary..
        for (int col=1; col<n; col++){
            dp[0][col] = grid[0][col] + dp[0][col-1];
        }

        // filling first col.. => iterator ka to row vary..
        for (int row=1; row<m; row++){
            dp[row][0] = grid[row][0] + dp[row-1][0];
        }

        // filling the dp array table 

        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[m-1][n-1]; 
    }
};


/*
iska tabulation method kaafi interesting laga mujhe ... because issey ye pata chal gaya ki matlab dp har ek 
state ke liye kaise value store karwa sakta hai.....

matlab jo dp[m][n] ki yaha ban rahi hai usme har state par jo value hai wo minimum value hogi to reach that 
cell starting from the 0, 0 th cell.... 

so obviously dp[m-1][n-1] mai store hoga... min. value to reach there starting from the (0,0) cell..

yaha ek cheej aur interesting mili like mai bas jaise 1d dp mai dp[0][0] = kucch karke leave kar deta tha... but yaha ek interesting constraint hai like ... 
    agar mujhe first row ke kisi bhi cell mai jaana hoga to ... usme confirm hai ki mai first row mai 
    rehka hi bas aage badh ke waha aaya honga... 
        similarly for first col....

        ye bhi mere base cases mai include honge.. and then aage ke cells compute honge 
        wahi aapka 1,1 se ...

*/