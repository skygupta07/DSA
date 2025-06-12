// maximalSquare.cpp

/*

Given an m x n binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.


Example 1:

Input: matrix = [["1","0","1","0","0"],
                ["1","0","1","1","1"],
                ["1","1","1","1","1"],
                ["1","0","0","1","0"]]

Output: 4


Example 2:

Input: matrix = [["0","1"],
                ["1","0"]]
Output: 1

Example 3:

Input: matrix = [["0"]]
Output: 0

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Variable to keep track of the maximum side length of a square found so far.
        int sz = 0;

        // Edge case: if the matrix is empty, return 0.
        if (matrix.empty()) return 0;

        // Create a 2D DP table `dp` where dp[i][j] represents the side length of the 
        // largest square whose bottom-right corner is at (i, j).
        vector <vector <int>> dp(m, vector<int>(n, 0));

        // Iterate over each cell in the matrix.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // If we are in the first row or column, or the current cell in the 
                // matrix contains '0', the largest square ending here is at most of size 1.
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0'; // Convert '0'/'1' to integer (0 or 1).
                }

                else {
                    // If the current cell contains '1', calculate the size of the largest square
                    // ending at (i, j) using the values of neighboring cells:
                    //   - dp[i-1][j] (above)
                    //   - dp[i][j-1] (left)
                    //   - dp[i-1][j-1] (top-left diagonal)

                    // this pattern is loved by most of us... but understood by very less of us...
                    //  +1 kyu add kiya === asking gun powder kyu nahi daala ... abey saale apna contribution nahi add karega kya...
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }

                // Update the maximum size of any square found so far.
                sz = max(sz, dp[i][j]);

            }
        }

        // The area of the largest square is the square of its side length.
        return (sz * sz);
    }
};
