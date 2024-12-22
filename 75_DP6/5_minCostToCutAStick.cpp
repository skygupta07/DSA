#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 2D DP array to store the results of subproblems
    int dp[101][101];
    
    // Recursive function to calculate the minimum cost to cut the stick
    int solve(int startStick, int endStick, vector<int> &cuts, int left, int right) {
        // Base case: if there are no cuts to make between left and right, return 0
        if (left > right) return 0;

        // If this subproblem has already been solved, return the stored result
        if (dp[left][right] != -1) return dp[left][right];

        // Initialize the minimum cost to a very high value (infinity)
        int cost = INT_MAX;

        // Iterate over all possible cuts within the range [left, right]
        for (int i = left; i <= right; i++) {
            // Calculate the cost for the left segment of the stick
            int leftCost = solve(startStick, cuts[i], cuts, left, i - 1);
            // Calculate the cost for the right segment of the stick
            int rightCost = solve(cuts[i], endStick, cuts, i + 1, right);
            // Calculate the current total cost including this cut
            int currCost = (endStick - startStick) + leftCost + rightCost;
            // Update the minimum cost if the current cost is lower
            cost = min(cost, currCost);
        }

        // Store the result in the DP array and return it
        return dp[left][right] = cost;
    }
    
    // Main function to find the minimum cost to cut the stick
    int minCost(int n, vector<int>& cuts) {
        // Initialize the DP array with -1, indicating unsolved subproblems
        memset(dp, -1, sizeof(dp));
        // Sort the cuts array to process cuts in ascending order
        sort(cuts.begin(), cuts.end());
        // Call the recursive function with initial boundaries of the stick
        return solve(0, n, cuts, 0, cuts.size() - 1);
    }
};
