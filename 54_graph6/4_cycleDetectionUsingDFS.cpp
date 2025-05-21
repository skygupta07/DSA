#include <bits/stdc++.h>
using namespace std;

// Graph ko adjacency list ke form mein represent kar rahe hain

// Graph ya adjacency list ka vector - declared globally for some reason I can't explain 
vector <list <int> > graph; 
int v; // Vertices ki count (number of nodes in the graph)

// Function to add edge in the graph (directed or undirected)
// 'bi_dir' agar true hai, toh edge bidirectional hoga
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest); // Source node se destination node tak edge
    if (bi_dir) { 
        graph[dest].push_back(src); // Bidirectional edge ke liye reverse connection
    }
}

// Graph ka adjacency list display karne ka function
void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> "; // Current vertex

        for (auto nbr : graph[i]) { 
            cout << nbr << " , "; // Is vertex ke saare neighbours
        }
        cout << "\n"; // Har vertex ke baad new line
    }
}

// Depth First Search (DFS) ka helper function
// 'src' current node hai, 'parent' se aya hai, aur 'vis' visited set hai

bool dfs(int src, int parent, unordered_set <int> &vis){

    vis.insert(src); // Current node ko visited mark karte hain

    for (auto neighbour : graph[src]) { // Saare neighbours ko traverse karo

        // Agar neighbour visited hai aur parent nahi hai, toh cycle detect hoti hai **
        if (vis.count(neighbour) && neighbour != parent) {
            return true; // Cycle mil gayi
        }
        // Agar neighbour visited nahi hai, toh DFS call karte hain
        if (!vis.count(neighbour)) {
            bool res = dfs(neighbour, src, vis); // Recursive DFS call
            
            if (res == true) return true; // Agar cycle mila, toh true return karo
        }
    }
    return false; // Cycle nahi mili ab tak finally false return karo
}

// Graph mein cycle detect karne ka function
bool has_cycle() {
    unordered_set<int> vis; // Visited nodes ka track rakhne ke liye set

    // Saare nodes ko traverse karte hain (for disconnected components)
    for (int i = 0; i < v; i++) {
        if (!vis.count(i)) { // Agar node visited nahi hai, toh DFS call karo

            bool result = dfs(i, -1, vis); // Parent -1 (source node ka koi parent nahi**)
            // source , parent, visited

            if (result == true) return true; // Agar cycle mili, toh true return karo
        }
    }
    return false; // Agar kahi bhi cycle nahi mili, toh false return karo
}



int main() {
    cin >> v; // Graph ke vertices ka input
    graph.resize(v, list<int>()); // Graph ko initialize karo
    int e; // Edges ka count
    cin >> e; // Graph ke edges ka input
    while (e--) {
        int s, d; // Source aur destination vertices
        cin >> s >> d; // Edge input
        add_edge(s, d, false); // Directed graph ke liye edge add karo
    }

    // Graph display karne ke liye (optional)
    // display();

    // Check if graph contains a cycle
    bool b = has_cycle();
    cout << b << "\n"; // 1 agar cycle hai, 0 agar nahi

    return 0;
}
