#include <bits/stdc++.h>
using namespace std;

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


class Solution{
public:

    bool isSafe(int node, int color[], bool graph[101][101], int n, int col){
        for (int k = 0; k < n; k++){
            if (k != node && graph[k][node] == 1 && color[k] == col) return false; 
        }
        return true;
    }

    bool solve(int node, int color[], int m, int N, bool graph[101][101]){
        // base case
        if (node == N) return true;
        
        // हर रंग की जाँच करें
        for (int i = 1; i <= m; i++){
            if (isSafe(node, color, graph, N, i)){

                color[node] = i;    // काम करें

                if (solve(node + 1, color, m, N, graph)) return true; // next index/node/samaan ke liye kaam kare..

                color[node] = 0;    // बैकट्रैक करें
            }
        }
        
        return false;
    }

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int N) {
        int color[N] = {0}; // N -> number of nodes

        if (solve(0, color, m, N, graph)) return true;

        return false;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
