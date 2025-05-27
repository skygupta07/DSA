#include <bits/stdc++.h>
using namespace std;

/*

You are given a 0-indexed 2D array grid of size 2 x n, 
where grid[r][c] represents the number of points at position (r, c) on the matrix. 
Two robots are playing a game on this matrix.

Both robots initially start at (0, 0) and want to reach (1, n-1). 
Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

At the start of the game, the first robot moves from (0, 0) to (1, n-1), 
collecting all the points from the cells on its path. 
For all cells (r, c) traversed on the path, grid[r][c] is set to 0. 
Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. 
Note that their paths may intersect with one another.

The first robot wants to minimize the number of points collected by the second robot. 
In contrast, the second robot wants to maximize the number of points it collects. 
If both robots play optimally, return the number of points collected by the second robot.
 

Example 1:


Input: grid = [[2,5,4],[1,5,1]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.



Example 2:


Input: grid = [[3,3,1],[8,5,2]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 3 + 1 + 0 = 4 points.


Example 3:


Input: grid = [[1,3,1,15],[1,3,3,1]]
Output: 7
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.
 

Constraints:

grid.length == 2
n == grid[r].length
1 <= n <= 5 * 104
1 <= grid[r][c] <= 105


*/


class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long minResult = LLONG_MAX;  // Start with a large number for the minimum score.
        long long row1Sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);  // Top row sum
        long long row2Sum = 0;  // Bottom row sum starts at 0.

        for (int i = 0; i < grid[0].size(); i++) {
            
            row1Sum -= grid[0][i];  // Move the top player forward, subtract current value.
            minResult = min(minResult, max(row1Sum, row2Sum));  // Update the minimum of the max scores.
            row2Sum += grid[1][i];  // Move the bottom player forward, add current value.
        }

        return minResult;  // Return the minimum maximum score.
    }
};




class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        const int n = grid[0].size();
        //Robot 1 goes down at 0
        
        long long U = reduce(grid[0].begin()+1, grid[0].end(), 0LL);
        long long D=0LL;

        long long Robot2=U; // Points obtained by Robot 2

        for (int i=1; i < n; i++) {
            U -= grid[0][i]; // Robot 1 goes down at i
            D += grid[1][i-1]; // Robot 2 takes path in both directions
            
            long long P=max(U, D); // optimized path for Robot 2
            Robot2 = min(Robot2, P);
        }

        return Robot2;
    }
};