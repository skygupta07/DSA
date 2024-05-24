#include <bits/stdc++.h>

int f(int idx, vector <int> &heights, vector <int> &dp){
    if (idx==0) return 0;

    if (dp[idx] != -1) return dp[idx];

    int left = f(idx-1, heights, dp) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;

    if (idx > 1) right = f(idx-2, heights, dp) + abs(heights[idx] - heights[idx-2]);

    return dp[idx] = min(left , right);
}


int frogJump(int n, vector<int> &heights) {
    vector <int> dp(n+1, -1);
    return f(n-1, heights, dp);
}

-----------
memoization (top down) and tabulation (bottom up)

#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights) {
    vector <int> dp(n, 0);

    dp[0] = 0;

    for (int i=1; i<n; i++){
        int fs = dp[i-1] + abs( heights[i] - heights[i-1] );
        int ss = INT_MAX;

        if (i>1) ss = dp[i-2] + abs( heights[i] - heights[i-2] );

        dp[i] = min(fs , ss);
     }
     return dp[n-1];
}

now whenever there will be f(idx-1) and f(idx-2) => surely there will be space optimisation...

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int prev = 0;
    int prev2 = 0;

    for (int i=1; i<n; i++){
        int fs = prev + abs(heights[i] - heights[i-1]); // first step
        int ss = INT_MAX;

        if (i>1) ss = prev2 + abs(heights[i] - heights[i-2]);   // second step

        int curri = min(fs, ss);
        
        prev2 = prev;
        prev = curri;
    }

    return prev;
}