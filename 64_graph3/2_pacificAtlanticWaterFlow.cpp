#include <iostream>
#include <vector>
using namespace std;
int main(){

}


class Solution {
public:
    void dfs(vector<vector<int>>& heights, int n, int m, int currRow, int currCol, vector<vector<bool>>& visited) {
        // base case ->

        // out of bound case 
        if (currRow < 0 || currCol < 0 || currRow >= n || currCol >= m || visited[currRow][currCol]) return;

        visited[currRow][currCol] = true;

        // Traverse in all 4 possible directions
        if (currRow - 1 >= 0 && heights[currRow][currCol] <= heights[currRow - 1][currCol]) 
            dfs(heights, n, m, currRow - 1, currCol, visited); // up
        if (currRow + 1 < n && heights[currRow][currCol] <= heights[currRow + 1][currCol]) 
            dfs(heights, n, m, currRow + 1, currCol, visited); // down
        if (currCol - 1 >= 0 && heights[currRow][currCol] <= heights[currRow][currCol - 1]) 
            dfs(heights, n, m, currRow, currCol - 1, visited); // left
        if (currCol + 1 < m && heights[currRow][currCol] <= heights[currRow][currCol + 1]) 
            dfs(heights, n, m, currRow, currCol + 1, visited); // right
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        if (n == 0) return {};
        int m = heights[0].size();

        vector<vector<bool>> pacificVisited(n, vector<bool>(m, false));
        vector<vector<bool>> atlanticVisited(n, vector<bool>(m, false));

        // DFS from Pacific Ocean borders (first row and first column)
        for (int i = 0; i < n; i++) {   // row change hogi column same rahega... vertically neeche tak jaake check kiya..
            dfs(heights, n, m, i, 0, pacificVisited);
        }
        for (int j = 0; j < m; j++) {
            dfs(heights, n, m, 0, j, pacificVisited);
        }

        // DFS from Atlantic Ocean borders (last row and last column)
        for (int i = 0; i < n; i++) {
            dfs(heights, n, m, i, m - 1, atlanticVisited);
        }
        for (int j = 0; j < m; j++) {
            dfs(heights, n, m, n - 1, j, atlanticVisited);
        }

        // Collect cells that can flow to both oceans
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

/*
0th row and 0th column -> pacific ocean
last row and last column -> atlantic ocean 

apply dfs from each cell if starting dfs from that cell we can reach both pacific and atlantic then 
result.push_back({i,j});
*/


try with bfs also ....

/*

mirror logic lagate hai hum log...
*/