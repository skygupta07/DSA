// flowerPlantingWithNoAdjacent.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] 
describes a bidirectional path between garden xi to garden yi. 

In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, 
for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, 
where answer[i] is the type of flower planted in the (i+1)th garden. 
The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.
 

Example 1:

Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].

Example 2:

Input: n = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]

Example 3:

Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]

*/


class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector <vector <int>> adj(n); // Adjacency list banayi, har garden ke neighbours store honge

        // Step 1: Adjacency list banana
        for (auto &path : paths){
            // 1-based to 0-based index (as per question format)
            int u = path[0] - 1; 
            int v = path[1] - 1;

            adj[u].push_back(v); // Garden u ka neighbour v hai
            adj[v].push_back(u); // Garden v ka neighbour u hai
        }

        vector <int> ans(n, 0); // Har garden ke liye flower type (0 means abhi assign nahi hua)

        // Step 2: Har garden ke liye flower assign karna greedily
        for (int i = 0; i < n; i++) {

            vector <bool> used(5, false); 
            // 1-based indexing ke liye size 5 liya, used[f] true hoga agar flower type f kisi neighbour ne use kiya ho

            // Step 2.1: Har neighbour ke flower type check karo
            for (int neighbor : adj[i]) {
                if (ans[neighbor] > 0) { // Agar neighbor ne koi flower liya hai
                    used[ans[neighbor]] = true; // Toh wo flower type mark kar do
                }
            }

            // Step 2.2: Ab pehle available flower type assign karo jo kisi neighbour ne use nahi kiya
            for (int f = 1; f <= 4; f++) {
                if (!used[f]) {
                    ans[i] = f; // Yeh flower assign kar diya current garden ko
                    break; // Ek hi flower chahiye, toh break
                }
            }
        }

        return ans; // Final flower assignment return
    }
};
