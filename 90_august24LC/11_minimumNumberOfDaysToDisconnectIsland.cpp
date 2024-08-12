#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int m, n;

    // DFS function to mark all connected land cells
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int currRow, int currCol) {
        // accha jaha se dfs call kiya hai wo to pata hi hai grid ki bondary mai hi hai.... but ha... ab jab 
        // new neighbour dekhunga...to unke upar to constraint lagana hoga...

        // calculate new neighbour cells ..
        for (auto [dr, dc] : {pair{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int nr = currRow + dr;
            int nc = currCol + dc;

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] == 1) {
                visited[nr][nc] = 1;
                dfs(grid, visited, nr, nc);
            }
        }
    }

    // Function to count the number of islands using DFS
    int countIsland(vector<vector<int>>& grid) {
        // dfs lagae ke hi count karunga..

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int island = 0;

        // traverse over each land...
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    island++;
                    visited[i][j] = 1; // Mark the starting cell as visited
                    dfs(grid, visited, i, j);
                }
            }
        }

        return island;
    }

    // Main function to find the minimum number of days to disconnect the island
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int initialIslandCount = countIsland(grid);

        if (initialIslandCount != 1) return 0;

        // now it is sure that there is exactly one island... so now ...ab har land (1) par jao usko zero karo...
        // and then check if now countIsland != 1 -> so ek step mai hi kaam chal gaya ......then backtrack also...

        // finally return 2 

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIsland(grid) != 1) return 1;
                    grid[i][j] = 1; // backtrack
                }
            }
        }

        return 2;
    }
};

/*

ekdum suruat mai countIslands se pata lagaya agar countIslands > 1 || countIslands == 0 return 0; (already disconnected)

// now there is one island
i will try iterating over each cell of island and flip to make water and then see if countIslands has increased to > 1   (kisi bhi cell ke liye ye ho jaata hai to theek hai answer 1 ho jaega.... ) -> we will backtrack also 

    otherwise 2 changes se to bade se bada grid bhi disonnect ho jaata hai....

as such yaha graph banane ke jarurat nahi hai .... traverse karne ke liye to nr , nc (direction pair wala use kar sakte hai...)

*/
