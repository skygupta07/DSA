#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the parent of a node in the Disjoint Set
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) return node; // Node is its own parent
        return parent[node] = findParent(parent[node], parent); // Path compression
    }

    // Function to union two sets
    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv; // Attach smaller rank tree under larger rank tree
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Function to find the sum of weights of edges of the Minimum Spanning Tree
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> edges; // {weight, u, v}

        // Convert adjacency list to edge list
        for (int u = 0; u < V; ++u) {
            for (auto& neighbor : adj[u]) {
                int v = neighbor[0];
                int wt = neighbor[1];
                if (u < v) { // Avoid duplicates
                    edges.push_back({wt, u, v});
                }
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end());

        // Initialize Disjoint Set (Union-Find)
        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; ++i) parent[i] = i;

        int mstWeight = 0; // Sum of MST weights
        int edgeCount = 0; // Number of edges included in MST

        // Process edges in sorted order
        for (auto& edge : edges) {
            int wt = edge[0], u = edge[1], v = edge[2];

            if (findParent(u, parent) != findParent(v, parent)) {
                mstWeight += wt; // Include this edge in MST
                unionSets(u, v, parent, rank); // Union the sets
                edgeCount++;

                if (edgeCount == V - 1) break; // Stop when MST is complete
            }
        }

        return mstWeight;
    }
};

/*
   Example Usage:
   Input:
   V = 4
   adj = {
       { {1, 1}, {2, 2} },
       { {0, 1}, {2, 3}, {3, 4} },
       { {0, 2}, {1, 3}, {3, 5} },
       { {1, 4}, {2, 5} }
   }

   Output:
   MST Weight: 8
*/
