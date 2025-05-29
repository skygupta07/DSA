#include <bits/stdc++.h>
using namespace std;


/*

Given n items, each with a specific weight and value, 
and a knapsack with a capacity of W, the task is to put the items in the knapsack 
such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

Note: You can either place an item entirely in the bag or leave it out entirely. 
Also, each item is available in single quantity.

Examples :

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.


Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).


Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.


Constraints:
2 ≤ val.size() = wt.size() ≤ 103
1 ≤ W ≤ 103
1 ≤ val[i] ≤ 103
1 ≤ wt[i] ≤ 103


*/

class Solution {
public:
    
    // Helper function to solve Knapsack using recursion + memoization (Top-Down DP)
    int solve(int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp, int n) {
        // Base case: Agar n = 0 (koi item nahi bacha) 
        // ya W = 0 (capacity khatam ho gayi), toh profit 0 hoga

        if (n == 0 || W == 0) return 0;

        // Memoization: Agar answer already calculated hai, toh direct return karenge
        if (dp[n][W] != -1) return dp[n][W];


        // Agar current item ki weight W se chhoti ya barabar hai, toh do options hain:
        // 1. Item include kar sakte hain (value add hogi + capacity kam hogi)
        // 2. Item exclude kar sakte hain (same capacity rahegi)
        if (wt[n-1] <= W) {

            return dp[n][W] = max(
                solve(W, val, wt, dp, n-1),                     // Exclude current item
                val[n-1] + solve(W - wt[n-1], val, wt, dp, n-1) // Include current item - to phir remaining knapsack ki capacity bhi update hogi...
            );

        }
        // Agar item ki weight capacity se zyada hai, toh sirf exclude karna padega
        else {
            return dp[n][W] = solve(W, val, wt, dp, n-1);
        }
    }

    // Main function to compute knapsack maximum value
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();  // Number of items
        
        // DP table (memoization array) initialize karenge with -1
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        // Recursive function call
        return solve(W, val, wt, dp, n);
    }
};



class Solution {
public:

    // Function to calculate the maximum value that can be obtained
    // from given items without exceeding the weight capacity W
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size(); // Number of items

        // Creating a 2D DP table:
        // dp[i][j] represents the maximum value that can be obtained 
        // using the first 'i' items and with a knapsack capacity of 'j'
        vector <vector<int>> dp(n + 1, vector <int>(W + 1, 0));

        // Filling the DP table using Bottom-Up Dynamic Programming approach
        for (int i = 1; i <= n; i++) { // Loop over items (1-based index)
            for (int j = 1; j <= W; j++) { // Loop over all possible capacities from 1 to W

                // Case 1: If the weight of the current item (wt[i - 1]) is less than or equal to current capacity j
                if (wt[i - 1] <= j) {
                    // We have two choices:
                    // 1. Include the current item: Add its value to the optimal solution of remaining capacity
                    //    (j - wt[i - 1]) using previous items (i - 1)
                    // 2. Exclude the current item: Carry forward the value without this item from previous row

                    dp[i][j] = max(
                        val[i - 1] + dp[i - 1][j - wt[i - 1]], // Include current item
                        dp[i - 1][j]                            // Exclude current item - kucch nahi include kar rahe iss bar to 
                        // phir jo pehle ka contribution h ussey count karo....
                    );

                }

                // Case 2: If the weight of the current item is more than the current capacity
                else {
                    
                    // We cannot include the current item, so the answer will be same as
                    // the answer without including this item
                    dp[i][j] = dp[i - 1][j];

                }
            }
        }

        // The value at dp[n][W] will hold the maximum value possible
        // using all 'n' items and full knapsack capacity 'W'
        return dp[n][W]; 
    }
};
