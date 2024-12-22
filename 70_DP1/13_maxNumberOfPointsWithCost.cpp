#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int r, c;  // Variables to store the number of rows (r) and columns (c) in the 'points' matrix.
    vector<vector<long long>> dp;  // 2D vector to store the computed results (memoization).
    vector<long long> left, right;  // Vectors to store the maximum values calculated from the left and right directions.

    // Helper function to calculate the maximum points we can collect from the first row to the current cell (i, j).
    long long f(int i, int j, vector<vector<int>>& points) {
        // Base case: If we are at the first row, the maximum points we can collect is just the points in this cell.
        if (i == 0) 
            return dp[i][j] = points[i][j];
        
        // If we've already computed the value for this cell, return it to avoid recomputation.
        if (dp[i][j] != -1) 
            return dp[i][j];

        // If j is 0, it means we are calculating for the first column of the row, so we need to compute the max values.
        if (j == 0) 
            right_left_max(i, points);

        // Return the maximum of left[j] or right[j] (which contain the maximum possible points from the previous row) plus the current cell's points.
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
    long long maxPoints(vector<vector<int>>& points) {
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
auto init = []()
{ 
    ios::sync_with_stdio(0);  // Disable synchronization between C and C++ standard streams.
    cin.tie(0);  // Untie cin from cout, allowing faster input operations.
    cout.tie(0);  // Untie cout from cin, allowing faster output operations.
    return 'c';  // This function returns a dummy character just to execute the block at the beginning.
}();