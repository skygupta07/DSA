// stoneGame2.cpp

/*

Alice and Bob continue their games with piles of stones. 
There are a number of piles arranged in a row, and each pile has a positive integer number of stones 
piles[i]. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles, 
where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.
Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Example 1:

Input: piles = [2,7,9,4,4]

Output: 10

Explanation:

If Alice takes one pile at the beginning, Bob takes two piles, 
then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left. 
In this case, Alice get 2 + 7 = 9 stones in total.

So we return 10 since it's larger.

Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104

 
Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 10pow4


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
     * helper(i, M): 
     *   Returns the **maximum score difference** (A - B) the current player can achieve 
     *   starting from index i and with the current value of M.
     *   i = current index in the pile array
     *   M = the current M value, which affects how many stones a player can take this turn
     *   p = the array of piles
     *   dp[i][M] = memoization table to store the result of state (i, M)
     */
    int helper(vector<vector<int>> &dp, int i, int M, vector<int> &p) {
        // Base case: If there are no more piles to take from
        if (i >= p.size()) return 0;

        // Return cached result if already computed
        if (dp[i][M] != -1) return dp[i][M];

        int total = 0;         // running total of stones taken in this iteration
        int ans = INT_MIN;     // stores the maximum score difference this player can achieve

        /*
         * Try taking x piles where x ranges from 1 to 2*M (as allowed by rules)
         * For every valid choice, simulate taking the next x piles and let the opponent play optimally
         */
        for (int j=0; j < 2*M; j++) {
            // If i+j is within bounds, add the pile to total

            if (i + j < p.size()) total += p[i + j];

            /*
             * After taking j+1 piles, the opponent plays from (i + j + 1) with max(M, j+1) as new M.
             * We subtract the opponent’s optimal result (because it’s a zero-sum game).
             */
            
            ans = max(ans, total - helper(dp, i + j + 1, max(M, j + 1), p));
        }

        // Save and return the result
        return dp[i][M] = ans;

    }

    int stoneGameII(vector<int>& piles) {
        // Initialize a memoization table large enough for constraints:
        // max n = 100, max M = 200 (since max(2M) can go up to ~200)
        vector <vector <int>> dp(101, vector<int>(202, -1));

        int sum = 0;

        // Compute total sum of stones
        for (auto el : piles) {
            sum += el;
        }

        // diff = A - B where A is first player, B is second player

                    // dp, idx, currentM, piles
        int diff = helper(dp, 0, 1, piles);

        // Since A + B = sum, and A - B = diff,
        // => A = (sum + diff)/2
        return (sum + diff) / 2;
    }
};
