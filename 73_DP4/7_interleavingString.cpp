// interleavingString.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), l = s3.length();

        // If the total lengths don't match, s3 can't be an interleaving of s1 and s2.
        if (m + n != l) return false;

        // DP table: dp[i][j] indicates whether s3[0...i+j-1] can be formed by interleaving
        // s1[0...i-1] and s2[0...j-1].
        vector <vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: Both s1 and s2 are empty strings.
        dp[0][0] = true;

        // Fill first column: Only characters from s1 can form s3.
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        // Fill first row: Only characters from s2 can form s3.
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // Fill the rest of the DP table.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || 
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        // The result is whether the entire s3 can be formed using s1 and s2.
        return dp[m][n];
    }
};
