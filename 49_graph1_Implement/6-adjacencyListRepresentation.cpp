#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m;    // no. of nodes and no. of edges..
    cin >> n>> m;

    // ha hum n+1 size ka hi banate hai adj
    vector <int> adj[n+1];  // square brackets ka significance hai...
    // abey ha saale wahi to tera array representation show karta h..

    for (int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }   
    
}

