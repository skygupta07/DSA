#include <bits/stdc++.h>
using namespace std;

// O(ElogE)

class Solution{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        //Brute Force prims algo O(N*N)
        //optimal sol prims algo O(NlogN)
        
        // int par[V];
        int key[V];
        bool mst[V];
        
        for(int i=0;i<V;i++){
            key[i]=INT_MAX,mst[i]=false;
        }
        
        key[0]=0;
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({key[0],0});  //key[],weight
        
        while(!pq.empty())
        {
            int u=pq.top().second;   //edge u-->v
            pq.pop();
            
            mst[u]=true;
            for(auto it:adj[u])
            {
                int v=it[0];
                int wt=it[1];
                
                if(mst[v]==false and wt<key[v])
                {
                    key[v]=wt;
                    pq.push({key[v],v});
                }
            }
        }
        
        int sum=0;
        for(int i=0;i<V;i++)
        {
            sum+=key[i];
        }
        return sum;
        
    }
};


/*
A tree in which we have N nodes and N - 1 edges and all nodes are reachable 
from each other is spanning tree.

-> minimum spanning tree will have the sum of all edge weights as minimum....

*/