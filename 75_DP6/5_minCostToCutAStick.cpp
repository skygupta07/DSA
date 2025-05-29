#include <bits/stdc++.h>
using namespace std;


/*

Given a wooden stick of length n units. The stick is labelled from 0 to n. 
For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, 
the total cost is the sum of costs of all cuts. When you cut a stick, 
it will be split into two smaller sticks 
(i.e. the sum of their lengths is the length of the stick before the cut).
 
Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.


Example 1:


Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:


The first cut is done to a rod of length 7 so the cost is 7. 
The second cut is done to a rod of length 6 (i.e. the second part of the first cut), 
the third is done to a rod of length 4 and the last cut is to a rod of length 3. 
The total cost is 7 + 6 + 4 + 3 = 20.


Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 
(as shown in the example photo 7 + 4 + 3 + 2 = 16).


Example 2:

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, 
the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
 

Constraints:

2 <= n <= 106
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
All the integers in cuts array are distinct.

*/


class Solution {
public:

    // DP array to store results of overlapping subproblems
    // dp[left][right] stores the minimum cost of making cuts between cuts[left] to cuts[right]
    int dp[101][101];

    /*
        Recursive helper function to calculate the minimum cost of cutting the stick
        from 'startStick' to 'endStick' when we are allowed to make cuts between indices
        'left' to 'right' in the 'cuts' array. - isliye solve function mai 0 to aakhri length paas kiya...
    */
    int solve(int startStick, int endStick, vector<int> &cuts, int left, int right) {

        // Base Case: Jab left > right ho gaya, matlab koi valid cut bacha hi nahi beech mein
        if (left > right) return 0;

        // If already computed, return stored result (memoization step)
        if (dp[left][right] != -1) return dp[left][right];

        // Abhi tak ka minimum cost track karne ke liye initialize karo
        int minCost = INT_MAX;

        // Try placing each cut from index 'left' to 'right'
        for (int i = left; i <= right; i++) {
            
            /*
                leftCost → Cost of making cuts on the left of cuts[i]
                rightCost → Cost of making cuts on the right of cuts[i]
                
                Yaani hum assume kar rahe hain ki cut[i] ko pehle kar diya,
                toh stick ka do parts ban gaya:
                  - [startStick, cuts[i]]
                  - [cuts[i], endStick]
                  
                In dono parts pe bhi recursively minimum cost find karenge
            */

            int leftCost = solve(startStick, cuts[i], cuts, left, i - 1);
            int rightCost = solve(cuts[i], endStick, cuts, i + 1, right);

            /*
                Abhi ka current cost kya hoga?
                Jab hum stick ko [startStick, endStick] ke beech cut karte hain
                toh cut karne ka cost = (endStick - startStick)
                Because that's the length of the stick we're cutting.

                Total cost = current cut cost + cost of left part + cost of right part
            */
            int currCost = (endStick - startStick) + leftCost + rightCost;

            // Update karo minCost agar yeh path better hai
            minCost = min(minCost, currCost);
        }

        // DP array mein store karo result for future reuse
        return dp[left][right] = minCost;
    }

    
    // Main function that sets up the problem
    int minCost(int n, vector<int> &cuts) {
        
        // DP array ko initialize karo -1 se (matlab sab subproblems unsolved hai abhi tak)
        memset(dp, -1, sizeof(dp));

        // Cutting points ko sort karna zaroori hai, 
        // because hum left to right try kar rahe hain cuts mein
        sort(cuts.begin(), cuts.end());
        
        /*
            Solve function call:
            - Initial stick boundaries: [0, n]
            - All cut points from index 0 to cuts.size()-1 available to process
        */
        return solve(0, n, cuts, 0, cuts.size() - 1);
    }
};

