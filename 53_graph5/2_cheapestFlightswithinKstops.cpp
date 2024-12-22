#include <bits/stdc++.h>
using namespace std;


/*
There are n cities connected by some number of flights.
 You are given an array flights where flights[i] = [fromi, toi, pricei] indicates 
 that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price 
from src to dst with at most k stops. If there is no such route, return -1.

*/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector <pair < int,int >>> gr(n);
        for (auto &e: flights){
            gr[e[0]].push_back( { e[1], e[2] });    
        }
        vector <int> dist( n, INT_MAX);
        queue <pair <int, int>> q;
        q.push({ src, 0});  // node , distance
        int stops = 0;

        while (stops <= k && !q.empty()){   // stops<=k taki steps aapke k+1 ho sake
            int sz = q.size();
            while (sz--){
                auto [node , distance ] = q.front();
                q.pop();

                for ( auto &[neighbour , price] : gr[node] ){
                    if (price + distance >= dist[neighbour]) continue;
                    dist[neighbour] = price + distance;
                    q.push( {neighbour, dist[neighbour]} );
                }
            }
            stops++;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};

/*


k stops means k+1 steps can be taken....
dijakstra's algorithm need to be applied ---- (single source shortest path)
using priority queue to fetch the minimum cost path...
but usme ab teen parameters pass karna bhai....

approach-2 apply simple bfs (i.e. level order traversal....)
level wise minimising my steps...
do level order traversal but do it untill all your steps are exhausted.....



*/