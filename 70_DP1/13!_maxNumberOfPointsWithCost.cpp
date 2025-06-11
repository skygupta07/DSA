// maxNumberOfPointsWithCost.cpp

/*

You are given an m x n integer matrix points (0-indexed). 
Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) 
will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked 
in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), 
picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.


Example 1:

Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.


Example 2:


Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.


Constraints:

m == points.length
n == points[r].length
1 <= m, n <= 10pow5
1 <= m * n <= 10pow5
0 <= points[r][c] <= 10pow5

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int r, c;  // Variables to store the number of rows (r) and columns (c) in the 'points' matrix.
    vector<vector<long long>> dp;  // 2D vector to store the computed results (memoization).
    vector<long long> left, right;  // Vectors to store the maximum values calculated from the left and right directions.

    // Helper function to calculate the maximum points we can collect from the first row to the current cell (i, j).
    long long f(int i, int j, vector <vector <int>> &points){

        // Base case: If we are at the first row, the maximum points we can collect is just the points in this cell.
        if (i == 0) return dp[i][j] = points[i][j];
        
        // If we've already computed the value for this cell, return it to avoid recomputation.
        if (dp[i][j] != -1) return dp[i][j];

        // If j is 0, it means we are calculating for the first column of the row, 
        // so we need to compute the max values.
        if (j == 0) right_left_max(i, points);

        // Return the maximum of left[j] or right[j] 
        // (which contain the maximum possible points from the previous row) 
        // plus the current cell's points.

        return dp[i][j] = max(left[j], right[j]) + points[i][j];
    }


    // Function to compute the maximum possible points from the previous row, both from the left side and the right side.
    void right_left_max(int i, vector<vector<int>>& points) {
        // Compute the maximum from the left to column j=0...c-1.
        left[0] = f(i - 1, 0, points);  // For the first column, it's just the value in dp for the previous row, same column.
        
        for (int j = 1; j < c; j++)
            left[j] = max(left[j - 1] - 1, f(i - 1, j, points));  // Max between moving left from the previous max or from dp.

        // Compute the maximum from the right down to column j=c-1...0.
        right[c - 1] = f(i - 1, c - 1, points);  // For the last column, it's just the value in dp for the previous row, same column.
        
        for (int j = c - 2; j >= 0; j--)
            right[j] = max(right[j + 1] - 1, f(i - 1, j, points));  // Max between moving right from the previous max or from dp.
    
    }

    // Main function to calculate the maximum points we can collect starting from any cell in the last row.
    long long maxPoints(vector <vector <int>> &points){

        r = points.size();  // Number of rows in the 'points' matrix.
        c = points[0].size();  // Number of columns in the 'points' matrix.

        // Initialize the dp array with -1 to indicate that no values have been computed yet.
        dp.assign(r, vector<long long>(c, -1));

        // Initialize the left and right vectors to store the maximum points as LLONG_MIN.
        left.assign(c, LLONG_MIN);
        right = left;

        long long ans = 0;  // Variable to store the maximum points we can collect overall.

        // Iterate over all columns in the last row to find the maximum points we can collect.
        for (int j = 0; j < c; j++)
            ans = max(ans, f(r - 1, j, points));  // Call the helper function for each cell in the last row.

        return ans;  // Return the maximum points that can be collected.
    
    }
};



// Initialization block to optimize input/output speed.
auto init = [](){ 

    ios::sync_with_stdio(0);  // Disable synchronization between C and C++ standard streams.
    
    cin.tie(0);  // Untie cin from cout, allowing faster input operations.
    cout.tie(0);  // Untie cout from cin, allowing faster output operations.
    
    return 'c';  // This function returns a dummy character just to execute the block at the beginning.
}();