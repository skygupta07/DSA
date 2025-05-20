#include <bits/stdc++.h>
using namespace std;

/*
You are given a positive integer n representing n cities numbered from 1 to n. 
You are also given a 2D array roads where roads[i] = [ai, bi, distancei] 
indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei.
The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times,
and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
 

Example 1:

Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. 

The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.


Example 2:

Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 
1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
 

Constraints:

2 <= n <= 105
1 <= roads.length <= 105

roads[i].length == 3
1 <= ai, bi <= n
ai != bi
1 <= distancei <= 104

There are no repeated edges.
There is at least one path between 1 and n.

*/

class Solution {
    public:
        int minScore(int n, vector <vector <int>> &roads) {
            int mini = INT_MAX; // Minimum edge weight track karne ke liye ek variable
    
            // Adjacency list banate hain jisme har node ke saath connected nodes aur unke distances store honge
            vector <vector <pair <int, int>>> adj(n + 1); // 1-based indexing ke liye size n+1 rakha
    
            // Graph ka adjacency list representation banate hain
            for (auto &road : roads) {
                adj[road[0]].push_back({road[1], road[2]}); // u -> (v, weight)
                adj[road[1]].push_back({road[0], road[2]}); // v -> (u, weight) (Graph undirected hai)
            }
    
            vector <bool> visited(n + 1, 0); 
            visited[1] = true; // Node 1 ko visited mark kar diya
            // Visited array jo track karega ki kaunsi nodes visit ho chuki hain
            
            queue<int> q; // BFS ke liye queue use karenge
            q.push(1); // BFS ko node 1 se start kar rahe hain
    
            // BFS traversal start karte hain
            while (!q.empty()) {
                int curr = q.front(); // Queue ke front element ko nikalte hain
                q.pop();

                visited[curr] = true; // Current node ko visited mark kar diya
    
                // Current node ke sabhi adjacent nodes ko traverse karenge
                for (auto &[nbr, dist] : adj[curr]) {
                    mini = min(mini, dist); // Minimum edge weight update kar rahe hain
    
                    if (!visited[nbr]) { // Agar node pehle visit nahi hui hai
                        visited[nbr] = 1; // Usko visited mark karenge
                        q.push(nbr); // BFS queue me daalenge
                    }
                }
            }
    
            return mini; // BFS complete hone ke baad sabse chhoti edge weight return karenge
        }
    };
    