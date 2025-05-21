/*

You are given a positive integer n representing the number of nodes in an undirected graph. 
The nodes are labeled from 1 to n.

You are also given a 2D integer array edges, where edges[i] = [ai, bi] 
indicates that there is a bidirectional edge between nodes ai and bi. 
Notice that the given graph may be disconnected.

Divide the nodes of the graph into m groups (1-indexed) such that:

Each node in the graph belongs to exactly one group.
For every pair of nodes in the graph that are connected by an edge [ai, bi], 
if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. 
Return -1 if it is impossible to group the nodes with the given conditions. 



Example 1:


Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
Output: 4
Explanation: As shown in the image we:
- Add node 5 to the first group.
- Add node 1 to the second group.
- Add nodes 2 and 4 to the third group.
- Add nodes 3 and 6 to the fourth group.
We can see that every edge is satisfied.
It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.



Example 2:

Input: n = 3, edges = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
It can be shown that no grouping is possible.
 

Constraints:

1 <= n <= 500
1 <= edges.length <= 104
edges[i].length == 2
1 <= ai, bi <= n
ai != bi
There is at most one edge between any pair of vertices.

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> adj[505];  // Adjacency list for storing the graph

    int col[505];  // Color array for bipartiteness check
    int dis[505][505];  // Distance array for shortest path calculations
    bool flag;  // Flag to check if the graph is bipartite or not
    vector<int> kara;  // Stores nodes of a connected component

    // DFS function to check if the graph is bipartite
    void dfs(int u, int c = 1) {
        col[u] = c;  // Assign color 'c' to node 'u'
        kara.push_back(u);  // Store node in component list
        for (int& v : adj[u]) {  // Traverse all neighbors of 'u'
            if (!col[v]) 
                dfs(v, 3 - c);  // Alternate color between 1 and 2
            else if (col[v] == c) 
                flag = 0;  // If adjacent nodes have the same color, it's not bipartite
        }
    }

    // BFS function to calculate shortest path distances from 'src' to all other nodes
    void bfs(int src) {
        for (int i = 1; i <= 500; i++) 
            dis[src][i] = 100001;  // Initialize all distances to a large value (infinity)
        
        dis[src][src] = 1;  // Distance of a node to itself is 1
        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int& v : adj[u]) {  // Traverse all neighbors
                if (dis[src][v] > dis[src][u] + 1) {  // If a shorter path is found
                    dis[src][v] = dis[src][u] + 1;
                    q.push(v);
                }
            }
        }
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Step 1: Initialize adjacency list and reset color array
        for (int i = 1; i <= n; i++) adj[i].clear();

        memset(col, 0, sizeof col);

        // Step 2: Construct the graph from edge list
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Step 3: Precompute shortest paths using BFS for all nodes
        for (int i = 1; i <= n; i++) bfs(i);

        int ans = 0;
        int in = 0;  // Counts the number of connected components

        // Step 4: Process each connected component
        for (int i = 1; i <= n; i++) {
            if (col[i] == 0) {  // If node 'i' is unvisited, start a DFS
                kara.clear();
                flag = 1;
                in++;  // Increment component count
                dfs(i);  // Perform DFS and check bipartiteness

                if (!flag) return -1;  // If not bipartite, return -1

                // Step 5: Find maximum shortest distance in the component
                int mxdis = 0;
                for (int& i : kara) {
                    for (int& j : kara) {
                        mxdis = max(mxdis, dis[i][j]);  // Get the longest shortest distance
                    }
                }
                ans += mxdis;  // Add the max distance of the component to the answer
            }
        }
        return ans;  // Return the final answer
    }
};
