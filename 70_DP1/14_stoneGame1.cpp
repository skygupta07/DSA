// stoneGame1.cpp

/*

Alice and Bob play a game with piles of stones. 
There are an even number of piles arranged in a row, and each pile has a positive integer 
number of stones piles[i].

The objective of the game is to end with the most stones. 
The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, 
a player takes the entire pile of stones either from the beginning or from the end of the row. 
This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.


Example 1:

Input: piles = [5,3,4,5]
Output: true


Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.


Example 2:

Input: piles = [3,7,2,3]
Output: true
 

Constraints:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles[i]) is odd.

*/


class Solution {
public:
    // Declare a DP table to store intermediate results
    // dp[i][j] will represent the **maximum difference** in score the current player can achieve over the other,
    // considering the subarray of piles from index i to j.
    int dp[501][501];

    // Recursive function to compute the maximum difference of score
    // the current player can achieve over the opponent.
    int solve(vector <int> &piles, int i, int j) {
        // Base case: if the range is invalid (no stones left to pick), the net score difference is 0
        if (i > j) return 0;

        // If this state has already been computed, return the cached result
        if (dp[i][j] != -1) return dp[i][j];

        /*
        The key idea is:
        - Each player wants to maximize their score difference.
        - When a player picks a pile (either i or j), the opponent plays optimally afterward.
        - So we subtract the result of the opponent’s best move from the stones we just took.

        Let's simulate both choices:
        */

        // Option 1: Pick the left pile at index i
        // After taking piles[i], the opponent plays on (i+1, j)
        // So the net gain is current pile - opponent's optimal result
        int pickLeft = piles[i] - solve(piles, i + 1, j);

        // Option 2: Pick the right pile at index j
        // Similarly, after taking piles[j], opponent plays on (i, j-1)
        int pickRight = piles[j] - solve(piles, i, j - 1);

        // Choose the move which gives the maximum advantage (score difference)
        return dp[i][j] = max(pickLeft, pickRight);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // Initialize the DP table with -1, meaning uncomputed
        memset(dp, -1, sizeof(dp));

        // Start the game from the full range of piles (0 to n-1)
        // If the final score difference > 0, Alice wins (since she plays first)
        return solve(piles, 0, n-1) > 0;
    }
};
