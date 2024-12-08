#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector <int> dist(V, 1e8);
        dist[S] = 0;
        
        // relax n - 1 times 
        for (int i=0; i<V-1; i++){
            for (auto edge: edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // relax nth time , if still distance vector is updating -> graph has negative
        // edge cycle ...
        
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        
        return dist;
    }
};



/*
dijakstra's algo was unable to find the shortest path for negative edge weights 
and falls under TLE for negative edge cycle..

so here comes the bellman ford algorithm that helps us to detect negative edge cycles...
-> bellman ford only works for the directed graph (nahi hai to banao pehle guru)

-> bellman ford helps you to detect negative cycles also
-> it is a single source shortest path algorithm

-> edges can be given in any particular order (imp)
-> relax all the edges (n-1) times sequentially 

where relaxation is : 
    if (dist[u] + w) < dist[v]{
        dist[v] = dist[u] + w;
    }


-> distance array as all infinity 

why n-1 times ??
    since in a graph of n nodes , you will take n-1 edges to reach from the first to last, thereby we 
    iterate for n-1 iterations...


---- how to detect negative edge cycles ??
    ye baat to confirm hai ki n-1 iterations mai shortest path mil hi jaana hai...
    chalo ek baar aur (nth times) relax karte hai ... and agar abhi bhi distance vector update ho raha hai 
    matlab kucch toh gadbad hai daya (i.e. presence of negative cycle )


*/