#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {

        // check if starting points are blocked
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int m = grid.size(); //rows
        int n = grid[0].size(); // cols

        // direction vector 
        vector <vector <int>> dirs {{1,0}, {-1,0}, {0, 1}, {0, -1}};

        // visited vector
        vector <vector <bool>> visited(m, vector <bool> (n, false));

        // min heap  -> storing values in time, row, col
        priority_queue < vector <int>, vector <vector <int> >, greater <> > pq;

        // start at top left corner -> threshold
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()){
            // get the current time, row and column.
            int time = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];

            pq.pop();

            // base case 
            if (row == m-1 && col == n-1) return time;

            // mark the current cell as visited
            if (visited[row][col]) continue;
            // nahi to in general kisi bhi cell pe land kiye to usko visited mark kiya...
            visited[row][col] = true;

            // explore the neighbouring cell as visited..

            for (auto dr: dirs){
                int r = row + dr[0];
                int c = col + dr[1];

                // grid boundaries check
                if (r<0 || r>=m || c<0 || c>=n) continue;

                // calculate the time required to reach the neighbouring cell

                int wait = (grid[r][c] - time)%2 == 0;  // even time ke case mai wait ki value 1 kar di...
                pq.push({max(grid[r][c] + wait, time + 1), r, c});
            }

        }

        return -1;
    }
};