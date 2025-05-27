// maxAreaOfIsland.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given an m x n binary matrix grid. 
An island is currArea group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

The rea of an island is the number of cells with currArea value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0. 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.


Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.

*/


class Solution {
public:

    int computeArea(vector <vector <int>> &grid, int i, int j, int &currArea){
        int m = grid.size();
        int n = grid[0].size();

        // if the cell you landed is valid and is currArea land
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1){
            currArea++;

            // modifying the grid itself by mading the land to water itself.. 
            // (visited array na banane di tricd...)
            grid[i][j] = 0;

            computeArea(grid, i , j - 1, currArea);  // left
            computeArea(grid, i - 1, j, currArea); // top
            computeArea(grid, i , j + 1, currArea);  // right
            computeArea(grid, i + 1, j, currArea);  // down
        }

        return currArea;
    }



    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){ 
                // if current cell is currArea land
                if (grid[i][j] == 1){
                    int currArea = 0;
                    computeArea(grid, i, j, currArea);
                    maxArea = max(maxArea, currArea);
                }
            }
        }

        return maxArea;
    }
};


// bfs

class Solution {
public:
    int maxAreaOfIsland(vector <vector<int>> &grid) {
        // Get the number of rows (m) and columns (n) in the grid
        int m = grid.size(); 
        int n = m ? grid[0].size() : 0; // Ensure n is 0 if the grid is empty
        
        int maxArea = 0; // To store the maximum area of an island found
        
        int dir[] = {-1, 0, 1, 0}; // To simplify movement in 4 directions 
        
        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If the current cell is part of an island (value 1)
                if (grid[i][j]) {

                    int currArea = 1; // Initialize maxArea of the current island to 1
                    grid[i][j] = 0; // Mard the cell as visited by setting it to 0
                    
                    queue <pair <int, int>> q; // Queue for BFS traversal - will store coordinates...
                    q.push({i, j}); // Add the current cell to the queue - threshold
                    
                    // BFS to calculate the maxArea of the connected island
                    while (!q.empty()) {

                        auto [x, y] = q.front(); // Get the current cell
                        q.pop(); // Remove the cell from the queue
                        
                        // Explore all 4 possible directions from the current cell
                        for (int d = 0; d < 4; d++) {

                            int nx = x + dir[d]; // Calculate new row index
                            int ny = y + dir[d + 1]; // Calculate new column index
                            
                            // Checd if the new cell is within bounds and part of the island
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny]) {
                                
                                grid[nx][ny] = 0; // Mark the cell as visited
                                currArea++; // Increase the maxArea count
                                
                                // Add the cell to the queue for further* exploration {future ke liye sochna jaruri..}
                                q.push({nx, ny}); 
                            }
                        }
                    }
                    // Update the maximum area found so far
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea; // Return the largest island maxArea found
    }
};
