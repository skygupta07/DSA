// minimumHeightTree.cpp

#include <bits/stdc++.h>
using namespace std;


/*

A tree is an undirected graph in which any two vertices are connected by exactly one path. 
In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi]
indicates that there is an undirected edge between the two nodes ai and bi in the tree, 

you can choose any node of the tree as the root. When you select a node x as the root, 
the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h)) 
are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.
The height of a rooted tree is the number of edges on the longest downward path between the root 
and a leaf.


Example 1:

Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 
which is the only MHT.


Example 2:

Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]  -> matlab kehne ka ye h ki ek baar jab 3 ko root node consider karenge and jab ek baar 4 ko 
// root node consider karenge tab hi minimum height tree aa rahi h...

*/



/*

 High-Level Logic:
Graph ko build karo using adjacency list.
Leaves (degree 1 waale nodes) ko identify karo.
BFS se leaf nodes ko layer by layer remove karo.
Jab 1 ya 2 nodes bachein, wahi MHT ke root nodes honge.



*/


class Solution {
public:

    // Function to find all the roots of Minimum Height Trees (MHTs)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        // ------------------------------ Intuition ------------------------------
        // The idea is to find the *center(s)* of the tree. For any tree, 
        // the minimum height is achieved when we root the tree at the center(s).
        //
        // A tree can have either one or two centers. These centers are the last 
        // remaining nodes if we keep removing the leaf nodes level by level 
        // (like peeling off layers of an onion). Eventually, 1 or 2 nodes will remain 
        // — these will be the roots of the Minimum Height Trees (MHTs).
        // ----------------------------------------------------------------------

        // Edge Case: Only one node in the tree, it is the root of MHT
        if (n == 1) return {0};

        // Step 1: Create adjacency list to represent the graph (tree)
        vector<vector<int>> graph(n);

        // Vector to store the degree (number of edges) of each node
        vector<int> degree(n, 0);

        // Fill adjacency list and degree count
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);  // Add edge u -> v
            graph[v].push_back(u);  // Add edge v -> u (since it's an undirected tree)

            degree[u]++;  // Increment degree for u
            degree[v]++;  // Increment degree for v
        }

        // Step 2: Initialize queue and push all leaf nodes (degree == 1)
        queue <int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);         // This is a leaf node
                // No need to mark as visited here explicitly; we reduce degree later
            }
        }

        // Step 3: Start BFS from all leaf nodes simultaneously
        // In each round, remove current leaves and find the new leaves.
        // The last remaining nodes in the queue are the centroids (MHT roots).
        vector<int> ans;  // Will store the last layer of nodes (MHT roots)

        while (!q.empty()) {
            int qSize = q.size();  // Number of nodes at current level (layer of leaves)
            ans.clear();           // Clear the previous layer

            for (int i = 0; i < qSize; i++) {
                int curr = q.front();
                q.pop();

                ans.push_back(curr);  // Add current node to potential MHT root list

                // Reduce degree of nbrs (simulate leaf removal)
                for (int nbr : graph[curr]) {
                    degree[nbr]--;

                    // If a nbr becomes a leaf, enqueue it for next round
                    if (degree[nbr] == 1) {
                        q.push(nbr);
                    }
                }
            }
        }

        // `ans` now contains 1 or 2 nodes which are the roots of Minimum Height Trees
        return ans;
    }

};
