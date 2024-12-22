#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector <vector <int> > &visited, int x, int y, int r, int c, bool &res) {
        // Check for out of boundary condition
        if (x < 0 || x >= r || y < 0 || y >= c) return;

        // Check if the cell is already visited or if grid2 has water
        if (visited[x][y] || grid2[x][y] == 0) return;

        // Mark the cell as visited
        visited[x][y] = 1;

        // If grid1 has water but grid2 has land, set res to false
        if (grid1[x][y] == 0) res = false;

        // Continue DFS for all 4 directions
        dfs(grid1, grid2, visited, x - 1, y, r, c, res); // up
        dfs(grid1, grid2, visited, x, y - 1, r, c, res); // left
        dfs(grid1, grid2, visited, x, y + 1, r, c, res); // right
        dfs(grid1, grid2, visited, x + 1, y, r, c, res); // down
    }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r = grid1.size();
        int c = grid1[0].size();

        vector<vector<int>> visited(r, vector<int>(c, 0));
        int count = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // Start DFS if the cell is land in grid2 and not visited
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    bool res = true;
                    dfs(grid1, grid2, visited, i, j, r, c, res);
                    // If the res flag is still true, it is a sub-island
                    if (res) count++;
                }
            }
        }

        return count;
    }
};
