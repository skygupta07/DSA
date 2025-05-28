// mColoringProblem.cpp

/*

You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], 
along with an integer m. Your task is to determine whether it is possible to color the graph 
using at most m different colors such that no two adjacent vertices share the same color. 
Return true if the graph can be colored with at most m colors, otherwise return false.

Note: The graph is indexed with 0-based indexing.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
Output: true
Explanation: It is possible to color the given graph using 3 colors, 
for example, one of the possible ways vertices can be colored as follows:

Vertex 0: Color 1
Vertex 1: Color 2
Vertex 2: Color 2
Vertex 3: Color 3


Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
Output: false
Explanation: It is not possible to color the given graph using only 2 colors because vertices 
0, 1, and 2 form a triangle.


Constraints:
1 ≤ V ≤ 10
1 ≤ E = edges.size() ≤ (V*(V-1))/2
0 ≤ edges[i][j] ≤ V-1
1 ≤ m ≤ V

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    // 🔒 Check karna hai ki 'node' par 'col' color lagana safe hai ya nahi
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
        for (int k = 0; k < n; k++) {
            // agar node aur k connected hain aur k pe wahi color hai jo hum lagana chahte hain
            if (k != node && graph[k][node] == 1 && color[k] == col) 
                return false;  // same color lag gaya hai neighbour pe → not safe
        }
        return true; // koi dikkat nahi → safe to color
    }

    // 🔁 Recursively try to assign colors to each node
    bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
        // 🎯 Base Case: Agar sabhi nodes color ho gaye → success
        if (node == N) return true;

        // har color ko try karo (1 se m tak)
        for (int i = 1; i <= m; i++) {
            if (isSafe(node, color, graph, N, i)) {
                color[node] = i; // ✅ current node ko color karo

                // 🔁 next node ke liye recurse karo
                if (solve(node + 1, color, m, N, graph)) 
                    return true; // agar aage solution mil gaya to return true

                // ❌ backtrack → agar aage color assign nahi ho paaya
                color[node] = 0;
            }
        }

        // koi color assign nahi ho paaya → return false
        return false;
    }

    // 🔍 Driver Function
    // Check if graph can be colored with at most M colors such that
    // no two adjacent vertices share same color
    bool graphColoring(bool graph[101][101], int m, int N) {
        int color[N] = {0}; // initially sabhi nodes uncolored hain (0)

        // start from node 0 and try to color all nodes
        if (solve(0, color, m, N, graph)) 
            return true;

        return false; // coloring possible nahi hai
    }
};

