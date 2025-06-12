// minCostClimbingStairs.cpp


/*

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.


Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.


Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function for recursion with memoization
    int solve(vector<int> &cost, int idx, vector<int> &dp) {
        int n = cost.size();

        // Base case: If we go out of bounds, no cost is needed
        if (idx >= n) return 0;

        // If already calculated, return the stored result
        if (dp[idx] != -1) return dp[idx];

        // Recursive step: Calculate the minimum cost from the current step
        int oneStep = solve(cost, idx + 1, dp); // Cost of taking one step
        int twoSteps = solve(cost, idx + 2, dp); // Cost of taking two steps

        dp[idx] = cost[idx] + min(oneStep, twoSteps); // Store the result in dp

        return dp[idx];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // DP array for memoization, initialized to -1
        vector<int> dp(n, -1);

        // Calculate the minimum cost starting from step 0 and step 1
        int startWithZero = solve(cost, 0, dp);
        int startWithOne = solve(cost, 1, dp);

        // The answer is the minimum of these two
        return min(startWithZero, startWithOne);
    }
};


/*

Explanation of the Approach:

1. `solve` function uses recursion with memoization (top-down DP) 
to calculate the minimum cost of reaching the top.

2. Base case: If the index goes beyond the last step, no additional cost is incurred.

3. Recurrence relation:
   - From the current step `idx`, we can either take one step or two steps forward.
   - The cost for each option is the current step cost plus the minimum of the remaining path costs.

4. Final result is the minimum of starting from step 0 or step 1.

*/


class Solution { // gives tle
public:
    
    int minCost = 0;
    
    int solve(vector <int> &cost, int idx){
        int n = cost.size();

        if (idx >= n) return 0;

        int oneStep = solve(cost, idx + 1);
        int twoStep = solve(cost, idx + 2);

        return cost[idx] + min(oneStep, twoStep);
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int startWithZero = solve(cost, 0);
        int startWithOne = solve(cost, 1);

        return min(startWithZero, startWithOne);
    }

};


/*
dp

min(startWithZero, startWithOne)  startWithZeroIndex

har step par min(takeOneStep, takeTwoStep) and cost[idx] to jodna hi hoga...


*/