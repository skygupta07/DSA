// numberOfOperationsToMakeNetworkConnected.cpp

#include <bits/stdc++.h>
using namespace std;

/*

There are n computers numbered from 0 to n - 1 connected by ethernet cables 
connections forming a network where connections[i] = [ai, bi] represents a connection 
between computers ai and bi. Any computer can reach any other computer directly or indirectly 
through the network.

You are given an initial computer network connections. 
You can extract certain cables between two directly connected computers, 
and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. 
If it is not possible, return -1. 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.


Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2


Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 

Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.

*/


class Solution {
    public: 
        int makeConnected(int n, vector <vector <int>> &connections) {
    
            // If there are fewer cables than (n - 1), it's impossible to connect all computers.
            if (connections.size() < n - 1) return -1;
            
            // Build an adjacency list for the network graph.
            vector< vector <int>> graph(n);
    
            for (const auto& conn : connections) {
                int u = conn[0], v = conn[1];
    
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
            
            // Create a visited array to keep track of visited computers.
            vector <bool> visited(n, false);
            int components = 0; // Count of connected components
            
    
            // Define a DFS function using lambda.
            function <void(int)> dfs = [&](int node) {
                visited[node] = true;
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        dfs(neighbor);
                    }
                }
            };
            
            // Run DFS for each computer that hasn't been visited yet.
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    dfs(i);
                    components++;  // Increase count for each connected component found.
                }
            }
            
    
            // Minimum operations required is the number of connected components minus one.
            return components - 1;
        }
    };
    