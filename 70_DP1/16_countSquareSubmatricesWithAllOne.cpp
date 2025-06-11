// countSquareSubmatricesWithAllOne.cpp

/*
Akash iski clear intuition explain karke verbally bata..

*/

#include <bits/stdc++.h>
using namespace std;


/*

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.


Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15

Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.


Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

*/

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        int m = matrix.size();        
        int n = matrix[0].size();     

        // Create a DP table of same size as matrix
        // dp[i][j] will store the size of the largest square ending at cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int count = 0;  // This will store the total number of square submatrices with all 1s


        // ---------- Fill the first row ----------
        // Base case: each cell in the first row can only form a 1x1 square at most
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];  // Copy as it is
            count += dp[0][j];        // Add to count (if it's 1, it's a valid square)
        }

        // ---------- Fill the first column ----------
        // Same reasoning as the first row, avoid double counting cell (0,0)
        for (int i = 1; i < m; i++) { // start from row 1 to avoid repeating cell (0,0)
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }

        // ---------- Fill the rest of the DP table ----------
        // Starting from (1,1), check each cell:
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                // If current cell has a 1, it can be part of a square
                if (matrix[i][j] == 1) {
                    /*
                     * dp[i][j] = 1 + minimum of:
                     *   - left (dp[i][j-1])
                     *   - top (dp[i-1][j])
                     *   - top-left diagonal (dp[i-1][j-1])
                     *
                     * This ensures that the square ends at (i,j) and extends only
                     * if all adjacent squares allow it to.
                     */
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }

                // Add the current dp[i][j] to the total count
                count += dp[i][j];
            }
        }

        return count; // Return total number of square submatrices with all 1s
    }
};
