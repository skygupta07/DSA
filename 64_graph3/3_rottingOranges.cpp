#include <iostream>
#include <vector>
using namespace std;
int main(){

}


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q; // Queue to store the coordinates of rotten oranges
        int freshCount = 0; // Count of fresh oranges
        
        // Initialize the queue with the positions of all rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {  // pushing all the rotten oranges into queue...
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        if (freshCount == 0) return 0; // No fresh oranges to rot -> na saap na basuri

        int time = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Directions for adjacent cells

        // BFS traversal
        while (!q.empty()) {
            int size = q.size();
            bool rottedAny = false; // Flag to check if any orange rotted in this minute

            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();    // ye sahi tareeka hai...pair fetch karne ka..
                q.pop();
                
                for (auto [dr, dc] : directions) {
                    int newRow = row + dr;
                    int newCol = col + dc;
                    
                    // if valid cell and contains the fresh orange...
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;   // neighbour ko bhi sada diya..
                        q.push({newRow, newCol});   // then sadi hui queue mai push kar diya...
                        freshCount--;   // issey mera freshCount ghat gaya....
                        rottedAny = true;   // ha ab rotted bhi ho gayi cheeje...
                    }
                }
            }

            if (rottedAny) {
                time++;
            }
        }

        return freshCount == 0 ? time : -1;
    }
};

/*
The BFS approach works as follows:
1. Initialize a queue with the positions of all initially rotten oranges and count the number of fresh oranges.
2. Process each level of the queue, representing the rotting process for one minute.
3. For each rotten orange, rot the adjacent fresh oranges and push them into the queue.
4. Increment the time each time we process a level where any orange rotted.
5. Return the time if all oranges have rotted, otherwise return -1 if there are any fresh oranges left.
*/


har minute immediate neighbour affect ho rahe hai...
multiple rotten oranges ho sakte hai ...and simultaneously wo apna padosiyo 
ko rot kar rahe honge....

/*
tree mai level order traversal karte time .... hum har level ke baad null push 
kar dete they ussey pata chal jata tha..ki naya level pe aa chuke hai..



*/