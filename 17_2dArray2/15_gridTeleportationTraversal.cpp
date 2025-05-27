#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Store teleport positions: character -> list of (i,j) positions
        unordered_map<char, vector<pair<int, int>>> teleport;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char ch = matrix[i][j];
                if (ch >= 'A' && ch <= 'Z') {
                    teleport[ch].push_back({i, j});
                }
            }
        }

        // Visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // Visited teleport chars
        unordered_set<char> usedTeleport;

        // BFS Queue: (i, j, moves)
        queue<tuple<int, int, int>> q;
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
