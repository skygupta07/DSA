#include <bits/stdc++.h>
using namespace std;


/*

You are given a 2D character grid matrix of size m x n, 
represented as an array of strings, where matrix[i][j] represents the cell 
at the intersection of the ith row and jth column. Each cell is one of the following:

'.' representing an empty cell.
'#' representing an obstacle.

An uppercase letter ('A'-'Z') representing a teleportation portal.

You start at the top-left cell (0, 0), 
and your goal is to reach the bottom-right cell (m - 1, n - 1). 

You can move from the current cell to any adjacent cell (up, down, left, right) 
as long as the destination cell is within the grid bounds and is not an obstacle.

If you step on a cell containing a portal letter and you haven't used that portal letter before, 
you may instantly teleport to any other cell in the grid with the same letter. 
This teleportation does not count as a move, but each portal letter can be used at most once 
during your journey.

Return the minimum number of moves required to reach the bottom-right cell. 
If it is not possible to reach the destination, return -1.
 

Example 1:

Input: matrix = ["A..",".A.","..."]
Output: 2

Explanation:

Before the first move, teleport from (0, 0) to (1, 1).
In the first move, move from (1, 1) to (1, 2).
In the second move, move from (1, 2) to (2, 2).


Example 2:

Input: matrix = [".#...",".#.#.",".#.#.","...#."]
Output: 13

Explanation:



Constraints:

1 <= m == matrix.length <= 103
1 <= n == matrix[i].length <= 103
matrix[i][j] is either '#', '.', or an uppercase English letter.
matrix[0][0] is not an obstacle.



*/

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Store teleport positions: character -> list of (i,j) positions
        unordered_map <char, vector<pair<int, int>>> teleport;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = matrix[i][j];

                if (ch >= 'A' && ch <= 'Z') {
                    teleport[ch].push_back({i, j});
                }

            }
        }

        // Visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Visited teleport chars
        unordered_set <char> usedTeleport;

        // BFS Queue: (i, j, moves)
        // kewal pair seekhne se hi kaam nahi chalta guru... tuple bhi seekhna padta h...
        
        queue <tuple <int, int, int>> q;
        q.push({0, 0, 0});
        visited[0][0] = true;


        // Direction vectors
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y, dist] = q.front();
            q.pop();

            // ✅ Reached destination
            if (x == m - 1 && y == n - 1) return dist;

            // 1. Normal 4-direction movement
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                // agar naye cell out of bound na ho and obstacle na ho to phir...
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny] && matrix[nx][ny] != '#') {
                    visited[nx][ny] = true;
                    q.push({nx, ny, dist + 1});
                }
                
            }

            // 2. Teleportation (zero cost, only once per character)
            char ch = matrix[x][y];

            if (ch >= 'A' && ch <= 'Z' && usedTeleport.find(ch) == usedTeleport.end()) {
                
                for (auto& [tx, ty] : teleport[ch]) {
                    if (!visited[tx][ty]) {
                        visited[tx][ty] = true;
                        q.push({tx, ty, dist});  // 🚀 Zero cost teleport
                    }
                }
                
                usedTeleport.insert(ch);  // mark teleportation as used
            }
        }

        // Not reachable
        return -1;
    }
};
