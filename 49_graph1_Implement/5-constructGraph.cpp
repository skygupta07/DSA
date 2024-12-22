#include <iostream>
using namespace std;
int main(){ // adjacency matrix representation...
    int n,m;    // no. of nodes and no. of edges..
    int adj[n+1][m+1];  // 1 based indexing.. 2d array...

    for (int i=0; i<m; i++){    // now taking edges input one by one...
        int u,v;    // u v waala hi sahi rehta hai...
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

// space complexity: O(2E) twice of number of edges...
/*
adjacency matrix is costly so we use adjacency list only...
yes binary tree can also be called graph..

connected component:->
this can be 4 different component of graph...
if (!visited)  call traversal(i)    
this is the reason why we need to maintain the visited array... 

/*
total degree of graph = 2*(number of edges)

*/



