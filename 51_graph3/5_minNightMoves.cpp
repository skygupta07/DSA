#include <vector>
#include <queue>
#include <utility>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        // Normalize the target position to the first quadrant since the problem is symmetric
        x = abs(x);
        y = abs(y);

        // Directions array for knight moves
        vector<pair<int, int>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        // BFS setup
        queue<pair<int, int>> q;    // create queue
        q.push({0, 0});             // threshold
        unordered_set<int> visited; // create visited
        visited.insert(0);  //  threshold    
                                //  Using a single integer for storing visited state

        int steps = 0;      


        // bfs steps...
        while (!q.empty()) {
            int qSize = q.size();   // ha ye bfs mai levels ya steps nikalwane ka tareeka hota hai...
            for (int i = 0; i < qSize; ++i) {
                pair<int, int> current = q.front();
                q.pop();
                
                int currX = current.first;
                int currY = current.second;

                if (currX == x && currY == y) {
                    return steps;
                }

                for (const auto& dir : directions) {
                    int newX = currX + dir.first;
                    int newY = currY + dir.second;

                    // Use a single integer for visited states, this helps avoid pair hashing
                    int hash = newX * 1000 + newY;

                    if (!visited.count(hash) && newX >= -1 && newY >= -1) {
                        q.push({newX, newY});
                        visited.insert(hash);
                    }
                }
            }
            steps++;
        }

        return -1; // Should never be reached since the answer is guaranteed to exist
    }
};



/*
start bfs from start point and see the minimum number of steps needed to reach 
final point 


say if you are currently at x,y then possible 8 moves are: 

x-2, y+1
x-1, y+2

x-2, y-1
x-1, y-2

x+2, y+1
x+1, y+2

x-2, y-1
x-1, y-2

*/




/*
In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction,
then one square in an orthogonal direction.

Return the minimum number of steps needed to move the 
knight to the square [x, y].  It is guaranteed the answer exists.

 
Example 1:

Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]

*/