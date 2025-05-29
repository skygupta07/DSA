#include <bits/stdc++.h>
using namespace std;

/*

You are in a city that consists of n intersections numbered from 0 to n - 1 
with bi-directional roads between some intersections. 
The inputs are generated such that you can reach any intersection from any other intersection 
and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] 
means that there is a road between intersections ui and vi that takes timei minutes to travel. 
You want to know in how many ways you can travel from intersection 0 to intersection n - 1 
in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. 
Since the answer may be large, return it modulo 10pow9 + 7.



Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4

Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6


Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
 

Constraints:

1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.

*/


class Solution {
public:

        int countPaths(int n, vector<vector<int>>& roads) {
            
            // Define a graph where each node contains pairs {neighbor, weight}
            vector <vector <pair<int, int>>> graph(n);
    
            // Construct the adjacency list representation of the graph
            for (const auto &road : roads) {
                int u = road[0];
                int v = road[1];
                int w = road[2];
    
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
            }
    
            // Distance array initialized to max value
            vector <long long> dist(n, LLONG_MAX);

            // Ways array to store the number of shortest paths to each node
            vector<int> ways(n, 0);
    
            // Constants for modulo operation
            const int MOD = 1e9 + 7;
    
            // Distance from the source (node 0) to itself is 0
            dist[0] = 0;
            ways[0] = 1;
    
            // Min-heap (priority queue) to process the nodes based on shortest distance
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            // distance, node
            
            // Push the source node with distance 0
            pq.push({0, 0});
    
            while (!pq.empty()) {
                
                auto [d, node] = pq.top();
                pq.pop();
    
                // If we already found a shorter path before, skip processing this node
                if (d > dist[node]) continue;
    
                // Iterate over all neighbors of the current node
                for (const auto &[nbr, time] : graph[node]) {
                    // If a shorter path is found to the neighbor
                    if (dist[node] + time < dist[nbr]) {
                        dist[nbr] = dist[node] + time;  // Update the shortest distance
                        ways[nbr] = ways[node];         // Copy the ways count
                        pq.push({dist[nbr], nbr});      // Push the updated node into the queue
                    } 
                    // If the same shortest path is found again, add the number of ways
                    else if (dist[node] + time == dist[nbr]) {
                        ways[nbr] = (ways[nbr] + ways[node]) % MOD;
                    }
                }
            }
    
            // Return the number of ways to reach the last node (n - 1)
            return ways[n - 1];
        }
    };
    