#include <iostream>
#include <vector>
using namespace std;
int main(){

}



vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    // Create adjacency list
    vector<vector<int>> adj(n + 1);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // Initialize distances with -1
    vector<int> distances(n + 1, -1);
    queue<int> q;

    // Start BFS from node s
    distances[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // Remove distance for node `s` itself and multiply distances by 6
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (i != s) {
            if (distances[i] != -1) {
                result.push_back(distances[i] * 6);
            } else {
                result.push_back(-1);
            }
        }
    }

    return result;
}