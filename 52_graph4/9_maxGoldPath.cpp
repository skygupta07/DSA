#include <bits/stdc++.h>
using namespace std;


/*
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
*/

class Solution {
public:
    // dx , dy wale vector aap globally hi bana liya karo taki fn mai pass na karna pade..

    vector <int> dx = {1,-1,0,0};
    vector <int> dy = {0,0,-1,1};


    int dfs(int i, int j, vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();

        // boundary condition -> agar kahi bhi backchod index pe pahuch gaya and waha se dfs call nahi ki 
        // ja sakti to simply return 0 from that end...
        if (i<0 || i >= m || j<0 || j>=n || grid[i][j] == 0) return 0;

        // ab ek index pe aagaye but waha se bhi jo dfs call lagani hai usme bhi to chahte hai ki wo aphi taraf se
        // best de ...wo apni taraf se max ans nikale....har direction mai ghum ghum ke dekh ke max laye....

        int maxSum = 0;
        int currVal = grid[i][j];   // waah bhai currVal to sabse pehle fetch kari bahar hi....

        for (int d=0; d<4; d++){
            int ni = i + dx[d]; // next i = ni
            int nj = j + dy[d]; // next j = nj

            grid[i][j] = 0;

            maxSum = max(maxSum, currVal + dfs(ni, nj, grid));  // recursive step -> ghum ghum ke max nikalega..
            grid[i][j] = currVal;   // backtracking ka step ki agar iss wale starting point se say kaam nahi chala to 
                                    // agle walo ke liye raasta badhiya kar diya...
        }
        return maxSum;
    }


    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // grid ke saare index pe jaata hu and non-zero element se bfs call kar deta hu...
        // aur jis bhi i,j se max mil jaye mere liye to usi ki jai...
        int ans = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] != 0) ans = max(ans, dfs(i,j,grid) );
            }
        }
        return ans;
    }
};


/*
left right up down wale question mai to aap simple dfs call hi lagate ho...
int return type tha fn ka to kucch aisa return kara ki saap bhi mar jaye aur laathi bhi naa tute... is return 0;

*/