#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector <long long> generateRowWays(int m){
    vector <long long> dp(m+1, 0);
    dp[0] = 1;  // 1 way to fill a row of width 0

    for (int i=1; i<=m; i++){
        if (i>=1) dp[i] = (dp[i] + dp[i-1]) % MOD;
        if (i>=2) dp[i] = (dp[i] + dp[i-2]) % MOD;
        if (i>=3) dp[i] = (dp[i] + dp[i-3]) % MOD;
        if (i>=4) dp[i] = (dp[i] + dp[i-4]) % MOD;
    }

    return dp;
}



long long legoBlocks(int n, int m){ // n = height, m = width
    vector <long long> rowWays = generateRowWays(m);

    vector <long long> totalWays(m+1, 0);

    for (int i=0; i<=m; i++){
        totalWays[i] = rowWays[i];
        for (int j=1; j<n; j++){
            totalWays[i] = (totalWays[i] * rowWays[i]) % MOD;
        }
    }

    vector <long long> validWays(m+1, 0);

    for (int i=1; i<=m; i++){
        validWays[i] = totalWays[i];

        for (int j=i; j<i; j++){
            validWays[i] = (validWays[i] - (validWays[j] * totalWays[i-j])%MOD + MOD) % MOD;
        }
    }

    return validWays[m];

}

int main(){

}