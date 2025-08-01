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

    vector <int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        // Step 1: Adjacency list banani hai — har garden ke neighbours ko track karne ke liye
        
        // n gardens hain, 0-based indexing use kar rahe hain
        vector <vector<int>> adj(n); 

        for (const auto &path : paths) {
            // path mein do gardens diye hain jinke beech edge hai
            int u = path[0] - 1; // 1-based index to 0-based index conversion
            int v = path[1] - 1;

            adj[u].push_back(v); // u ka neighbour v
            adj[v].push_back(u); // v ka neighbour u (undirected graph)
        }

        // Step 2: Har garden ko ek flower assign karna hai aise ki koi 2 adjacent gardens ka flower type same na ho
        // 0 ka matlab abhi tak flower assign nahi hua
        vector <int> assignedFlowers(n, 0);

        // Total 4 types of flowers available: 1, 2, 3, 4
        // Problem guarantee karta hai ki kisi garden ke maximum 3 neighbours honge,
        // isiliye 1 flower hamesha assign kar paayenge

        // har garden par gaye..
        for (int i = 0; i < n; i++) {
            // used[f] = true ka matlab flower type f kisi neighbour ne already le liya hai
            // Index 0 ko ignore karenge, flower types 1-4 hain, isiliye size = 5

            // har garden mai lagane ke liye 4 phool le gaye ..{1 se 4 number wale...}
            vector <bool> used(5, false);

            // Step 2.1: Check karo current garden i ke neighbours ne kaunse flower types use kiye hain
            for (int neighbor : adj[i]) {
                int neighborFlower = assignedFlowers[neighbor];

                if (neighborFlower != 0) {
                    used[neighborFlower] = true; // mark kar diya ki yeh flower type already occupied hai
                }
            }

            // Step 2.2: Greedily pehla available flower assign karo jo kisi neighbour ne use nahi kiya
            for (int f = 1; f <= 4; f++) {

                if (!used[f]) {
                    assignedFlowers[i] = f;
                    
                    break; // ek hi flower assign karna hai, break kar jaao
                }

            }
        }

        // Final flower assignment for all gardens return karo
        return assignedFlowers;
    }
};


class Solution {
public:

    vector <int> gardenNoAdj(int n, vector <vector <int>> &paths) {
        
        vector <vector <int>> adj(n); // Adjacency list banayi, har garden ke neighbours store honge

        // Step 1: Adjacency list banana
        for (const auto &path : paths){
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
            // 1-based indexing ke liye size 5 liya, 
            // used[f] true hoga agar flower type f kisi neighbour ne use kiya ho

            // Step 2.1: Har neighbour ke flower type check karo
            for (int neighbor : adj[i]) {
                
                // Agar neighbor ne koi flower liya hai
                if (ans[neighbor] > 0) { 

                    used[ans[neighbor]] = true; // Toh wo flower type mark kar do
               
                }

            }

            // Step 2.2: Ab pehle available flower {greedily thinking} type assign karo 
            // jo kisi neighbour ne use nahi kiya

            for (int f = 1; f <= 4; f++) {
                
                if (!used[f]) {
                    ans[i] = f; // Yeh flower assign kar diya current garden ko
                    break; // Ek hi flower chahiye, toh break
                }

            }

        }

        // Final flower assignment return
        return ans; 

    }
};
