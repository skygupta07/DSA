// topologicalSorting.cpp

// topological sorting is linear ordering of vertices such that if there is an edge between u and v, 
// u appears before v in the ordering....

 
#include <bits/stdc++.h>
using namespace std;


/*

Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented 
as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. 
Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices 
such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. 
If your returned Topological sort is correct then the output will be true else false.

Examples:

Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true
Explanation: The output true denotes that the order is valid. 
Few valid Topological orders for the given graph are:

[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]

Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]


Constraints:
2  ≤  V  ≤  10pow3
1  ≤  E = edges.size()  ≤  (V * (V - 1)) / 2

*/

class Solution {
  public:
  
    void dfs(int node, stack <int> &stk, vector <int> &visited, vector <vector <int>> &graph){
        // now here in the dfs function mark it visited as soon as you saw it...
        visited[node] = 1;
        
        for (const auto &nbr : graph[node]){
            if (!visited[nbr]){
                dfs(nbr, stk, visited, graph);
            }
        }
        
        stk.push(node);
    }
  
  


    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // V is number of vertices..
        vector <vector <int>> graph(V);
        
        for (const auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            // only directed edges
            graph[u].push_back(v);
        }
        
        // intially all marked as not visited...
        vector <int> visited(V, 0);
        
        stack <int> stk;
        
        // har vertices pe jaa and agar wo visited nahi h to phir 
        // waha se dfs call kar...
        
        for (int i=0; i<V; i++){
            
            // iff the ith node is not visited then only call the dfs from there...
            if (!visited[i]){
                dfs(i, stk, visited, graph);
            }

        }
        
        vector <int> topoOrder;
        
        while (!stk.empty()){
            topoOrder.push_back(stk.top());
            stk.pop();
        }
        
        return topoOrder;
        
    }
};


/*
using dfs

put those nodes into stack for which bfs call has been made...

*/

// bfs

// using kahn's algo...

class Solution {
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[]){
		int indegree[V] = {0};

		for (int i = 0; i < V; i++) {
            // u se v tak edge h to indegree v ki hi increase hoti h...
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		vector <int> topo;

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
            
		}

		return topo;

	}
};


int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}


// if topoSort gives count = V => then there is no cycle 
// else there will surely be a cycle in the graph...


