// uniquePaths3.cpp


/*


You are given an m x n integer array grid where grid[i][j] could be:

-1 representing obstacles that we cannot walk over.
0 representing empty squares we can walk over.

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.


Return the number of 4-directional walks from the starting square to the ending square, 
that walk over every non-obstacle square exactly once.
 

Example 1:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2

Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)



Example 2:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4

Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)


Example 3:


Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.

Note that the starting and ending square can be anywhere in the grid.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.


*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    int dfs(vector<vector<int>>& grid, int i, int j, int remainingCells) {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds or obstacle check
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) return 0;

        // If we reach the endpoint (2) and have visited all cells
        if (grid[i][j] == 2) return (remainingCells == 0) ? 1 : 0;

        // Mark the cell as visited (pura visited vector banane ki need nahi h...
        //  just simply us cell ko hi aisa kar do ki wo visited cell ban jaye... then recursive call ke baad dubara revert kar dena state ko ....)
        
        grid[i][j] = -1;

        // Explore all 4 possible directions
        int paths = dfs(grid, i - 1, j, remainingCells - 1) +
                    dfs(grid, i + 1, j, remainingCells - 1) +
                    dfs(grid, i, j - 1, remainingCells - 1) +
                    dfs(grid, i, j + 1, remainingCells - 1);

        // Backtrack to restore the grid state for other paths
        grid[i][j] = 0;

        return paths;
    }


    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int startX, startY, emptyCells = 0;

        // Find the starting point and count empty cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }

                else if (grid[i][j] == 0) {
                    emptyCells++;
                }
                
            }
        }

        // Perform DFS
        return dfs(grid, startX, startY, emptyCells + 1); // +1 to count start cell
    }

};




/*
class Solution { // wrong...
public:

    void dfs(vector <vector <int>> &grid, vector <vector <bool>> &visited, int count, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) return;

        visited[i][j] = true;

        if (grid[i][j] == 2){
            count++;
            return;
        }

        if (!visited[i-1][j]) dfs(grid,visited, count , i-1, j);
        if (!visited[i][j-1]) dfs(grid, visited, count , i, j-1);
        if (!visited[i+1][j]) dfs(grid, visited, count , i+1, j);
        if (!visited[i][j+1]) dfs(grid, visited, count , i, j+1);
    }



    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector <vector <bool>> visited (m, vector <bool> (n, false));

        int count = 0;

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1){
                    dfs(grid, visited, count, i, j);
                    return count;
                }
            }
        }
        return 0;
    }
};

*/