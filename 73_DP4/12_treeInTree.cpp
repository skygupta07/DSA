// treeInTree.cpp

#include <bits/stdc++.h>
using namespace std;

/*
For a tree with N vertices numbered from 1 to N and edges connecting vertices ai and Bi,
solve the problem for each X from 1 to N.

The problem requires finding the number of non-empty subsets V of the tree's vertices,
such that the subgraph induced by V has exactly X connected components.

The final answer should be modulo 998244353.qq
*/

const int MODULO = 998244353;  // Given large prime modulus for calculations
const int MAX_NODES = 5010;  // Maximum number of nodes in the tree

vector<int> adjacencyList[MAX_NODES];  // Adjacency list to store tree edges
int dp[MAX_NODES][2][MAX_NODES];  // DP table for storing subset counts
int totalNodes;  // Total number of nodes in the tree

// Function to add an undirected edge in the tree
void addEdge(int nodeA, int nodeB) {
    adjacencyList[nodeA].push_back(nodeB);
    adjacencyList[nodeB].push_back(nodeA);
}

// Function to compute all valid subsets using DP on trees (DFS-based DP)
int computeSubsets(int currentNode, int parentNode) {
    int subtreeSize = 1;  // Size of the current subtree, initially just the node itself

    dp[currentNode][0][0] = 1;  // Case where we do not select the current node
    dp[currentNode][1][1] = 1;  // Case where we select the current node

    // Traverse all adjacent nodes (children in the DFS tree)
    for (int neighbor : adjacencyList[currentNode]) {
        if (neighbor == parentNode) continue;  // Ignore the parent node

        int subtreeCount = computeSubsets(neighbor, currentNode);  // Recursively process child

        // **Updating DP table for cases where the current node is NOT selected**
        for (int selectedNodes = subtreeSize; selectedNodes >= 0; --selectedNodes) {
            for (int newNodes = subtreeCount; newNodes >= 1; --newNodes) {
                dp[currentNode][0][selectedNodes + newNodes] = 
                    (dp[currentNode][0][selectedNodes + newNodes] + 
                    (dp[currentNode][0][selectedNodes] * 
                    (dp[neighbor][0][newNodes] + dp[neighbor][1][newNodes]) % MODULO) % MODULO) % MODULO;
            }
        }

        // **Updating DP table for cases where the current node IS selected**
        for (int selectedNodes = subtreeSize; selectedNodes >= 1; --selectedNodes) {
            for (int newNodes = subtreeCount; newNodes >= 1; --newNodes) {
                // Case 1: Current node selected, child node is not necessarily selected
                dp[currentNode][1][selectedNodes + newNodes] = 
                    (dp[currentNode][1][selectedNodes + newNodes] + 
                    (dp[currentNode][1][selectedNodes] * dp[neighbor][0][newNodes]) % MODULO) % MODULO;
                
                // Case 2: Current node selected, child node is also selected
                dp[currentNode][1][selectedNodes + newNodes - 1] = 
                    (dp[currentNode][1][selectedNodes + newNodes - 1] + 
                    (dp[currentNode][1][selectedNodes] * dp[neighbor][1][newNodes]) % MODULO) % MODULO;
            }
        }

        subtreeSize += subtreeCount;  // Update the size of the subtree
    }

    return subtreeSize;  // Return the total size of the subtree rooted at 'currentNode'
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> totalNodes;  // Input number of nodes

    // Input edges and construct the tree
    for (int i = 1; i < totalNodes; ++i) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        addEdge(nodeA, nodeB);
    }

    computeSubsets(1, 0);  // Start DFS from node 1 (assuming it as the root)

    // Output the number of valid subsets of each size from 1 to totalNodes
    for (int i = 1; i <= totalNodes; ++i) {
        cout << (dp[1][0][i] + dp[1][1][i]) % MODULO << endl;
    }

    return 0;
}
