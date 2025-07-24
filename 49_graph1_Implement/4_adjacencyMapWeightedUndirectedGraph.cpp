// adjacencyMapWeightedUndirectedGraph.cpp

#include <bits/stdc++.h>
using namespace std;


// Global graph represented as vector of unordered_maps (Adjacency list with weights)
vector <unordered_map <int, int>> graph;
int v; // number of vertices

// Add an edge from src to dest with weight 'wt'. If bi_dir = true, make it bidirectional.
void addEdge(int src, int dest, int wt, bool bi_dir = true) {
    graph[src][dest] = wt;

    if (bi_dir) graph[dest][src] = wt;
}

// Display the adjacency list of the graph
void display() {

    cout << "\nGraph Representation (Adjacency List):\n";

    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";

        for (auto &nbr : graph[i]) {
            cout << "[" << nbr.first << ", wt=" << nbr.second << "] ";
        }

        cout << "\n";
    }

}

int main() {
    cout << "Enter number of vertices: ";
    cin >> v;
    graph.resize(v); // resize graph to hold v vertices

    cout << "Enter number of edges: ";
    int e;
    cin >> e;

    cout << "Enter edges in the format: src dest weight\n";
    
    while (e--) {
        int src, dest, wt;

        cin >> src >> dest >> wt;

        addEdge(src, dest, wt, false); // false = directional graph
    }

    display();

    return 0;
}
