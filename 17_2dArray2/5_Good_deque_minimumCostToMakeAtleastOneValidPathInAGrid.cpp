// minimumCostToMakeAtleastOneValidPathInAGrid.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an m x n grid. Each cell of the grid has a sign pointing to the next cell 
you should visit if you are currently in this cell. The sign of grid[i][j] can be:

1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])


Notice that there could be some signs on the cells of the grid that point outside the grid.

You will initially start at the upper left cell (0, 0). 
A valid path in the grid is a path that starts from the upper left cell (0, 0) 
and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. 
The valid path does not have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
Return the minimum cost to make the grid have at least one valid path.

 

Example 1:


Input: grid = [[1,1,1,1],
                [2,2,2,2],
                [1,1,1,1],
                [2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
The total cost = 3.


Example 2:


Input: grid = [ [1,1,3],
                [3,2,2],
                [1,1,4]]
Output: 0
Explanation: You can follow the path from (0, 0) to (2, 2).
Example 3:


Input: grid = [[1,2],
              [4,3]]

Output: 1
 

Constraints:

m == grid.length
n == grid[i].length

1 <= m, n <= 100
1 <= grid[i][j] <= 4


*/

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Directions for each type of arrow - minusone zero one zero ,,then uska ulta...

        vector <pair <int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Deque for 0-1 BFS
        deque <pair<int, int>> dq;
        
        // Cost array to track the minimum cost to reach each cell
        vector <vector <int>> cost(m, vector<int>(n, INT_MAX));
        
        // Start from the top-left cell with cost 0
        dq.push_front({0, 0});
        cost[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            // If we've reached the bottom-right cell, return the cost
            if (x == m - 1 && y == n - 1) return cost[x][y];

            // Explore all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int newX = x + directions[i].first;
                int newY = y + directions[i].second;

                // Check bounds
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {

                    // Cost of moving to this cell
                    int newCost = cost[x][y] + (grid[x][y] == i + 1 ? 0 : 1);

                    // Update the cost and add to the deque if we find a cheaper path
                    if (newCost < cost[newX][newY]){
                        
                        cost[newX][newY] = newCost;

                        // Push to the front if no cost, otherwise push to the back
                        if (grid[x][y] == i + 1){
                            dq.push_front({newX, newY});
                        }
                        else {
                            dq.push_back({newX, newY});
                        }
                    }
                }
            }
        }

        return -1; // If no valid path exists (theoretically shouldn't happen)
    }
};
