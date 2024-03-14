#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;    // no. of nodes and no. of edges..
    cin >> n>> m;
    vector <int> adj[n+1];  // square brackets ka significance hai...

    for (int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }   
}

