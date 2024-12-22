class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        // Edge case: both string and pattern are empty
        if (p_len == 0) return s_len == 0;
        
        // Edge case: pattern is only '*'
        if (p == "*") return true;
        
        // Create a DP table
        vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));
        dp[0][0] = true; // Empty pattern matches empty string

        // Fill the first row for patterns like '*', '**', '***', etc.
        for (int j = 1; j <= p_len; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= s_len; ++i) {
            for (int j = 1; j <= p_len; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[s_len][p_len];
    }
};
