#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helper(vector <vector <int> > &dp, int i, int M, vector <int> &p){   // returns diff 
        if (i >= p.size()) return 0;

        if (dp[i][M] != -1) return dp[i][M];

        int total = 0;
        int ans = INT_MIN;

        for (int j=0; j<2*M; j++){
            if (i + j < p.size()) total += p[i+j];

            ans = max(ans, total - helper(dp, i+j+1, max(M, j+1), p));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        vector <vector <int> > dp(101, vector <int> (202, -1));

        int sum = 0;
        for (auto el : piles){  // a+b
            sum += el;
        }

        int diff = helper(dp,0, 1, piles); // a-b
        return (sum + diff)/2;  // a
    }
};