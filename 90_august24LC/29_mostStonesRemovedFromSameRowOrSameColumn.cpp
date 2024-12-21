#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector <int>> &stones, vector <bool> &visited, int idx){
        int n = stones.size();

        visited[idx] = true;
        
        for (int i=0; i<n; i++){
            // ith stone visited na ho and ya to same row ya same column jaisa ho...
            if (!visited[i] && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1])){
                // jaao apne saathi ko search karo....
                dfs(stones, visited, i);
            }
        }
    }


    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector <bool> visited(n, 0);
        int count = 0;

        for (int i=0; i<n; i++){
            if (visited[i]) continue;
            dfs(stones, visited, i);
            count++;
        }

        return n-count;
    }
};


/*
answer is number of stones - number of connected components...

where connected components will be from the same row, same column element ....\



har stone par traverse kara..... 
ek n stones ki visited bool array banai...

dfs call laga di uss index se ....

andar dfs call mai 


*/