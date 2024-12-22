#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map <int, vector<int>> graph; // int karke dekhiyo..nahi chalega ... because push_back vector<int> ke hi karan hoga...

        for (auto e : edges){       // establishing bidirectional connection between edges in form of key and value 
                                    // pairs in map....
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector <bool> visited(n,0);
        queue <int> q;

        q.push(source);
        visited[source] = 1;

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            if (curr == destination) return true;

            for (auto &node : graph[curr]){
                if (!visited[node]){
                    visited[node] = 1;
                    q.push(node);
                }
            }
        }
        return false;
    }

};


/*
method 1 -> form a graph using the adjacency list given adn check if the path exists using bfs...

*/



// ---------

 class Solution {
public:
    vector <int> parent;
    int findParent(int node){
        return parent[node] == node ? node : (parent[node] = findParent(parent[node]));
    }

    void makeSameGroup(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        parent[pu] = pv;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);

        for (int i=0; i<n; i++) parent[i] = i;

        for (auto e: edges) makeSameGroup(e[0] , e[1]);

        return findParent(source) == findParent(destination);  
    }
};


/*
method3 -> We don't really to need to find the length of the path. Since this is an undirected graph,
we just need to check if start and end are in the same connected component. So we use union find
*/