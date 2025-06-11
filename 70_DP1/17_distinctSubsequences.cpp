// distinctSubequences.cpp

#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.


Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit


Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 
Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.

*/


class Solution {
    public:
    
        // Recursive function to count distinct subsequences of `s` that match `t`
        int solve(string s, string t, int m, int n, vector <vector <long long>> &dp) {
            // Base case 1: If both strings are empty, there is exactly one matching subsequence (empty subsequence)
            if (m == 0 && n == 0) return 1;
            
            // Base case 2: If `s` is exhausted but `t` is not, no valid subsequence can be formed
            if (m == 0) return 0;
            
            // Base case 3: If `t` is exhausted, the empty subsequence of `s` always matches
            if (n == 0) return 1; // Every string has an empty subsequence
    
            if (dp[m][n] != -1) return dp[m][n];

            // Case 1: If the last characters of `s` and `t` match
            if (s[m - 1] == t[n - 1]) {
                // We have two choices:
                // 1. Include this character and move both pointers (m-1, n-1)
                // 2. Exclude this character from `s` and just move `m-1`
                return dp[m][n] = solve(s, t, m - 1, n - 1, dp) + solve(s, t, m - 1, n, dp);
            }
    
            // Case 2: If last characters don't match, we must exclude `s[m-1]` and move `m-1`
            return dp[m][n] = solve(s, t, m - 1, n, dp);

        }
    
        // Main function to compute the number of distinct subsequences
        int numDistinct(string s, string t) {
            int m = s.length(); // Length of string `s`
            int n = t.length(); // Length of string `t`
    
            vector <vector <long long>> dp(m+1, vector <long long> (n+1, -1));
    
            // Call the recursive function
            return solve(s, t, m, n, dp);
        }
    };



class Solution {
public:
    // Function to compute the number of distinct subsequences of `s` that equal `t`
    int numDistinct(string s, string t) {
        int m = s.length();  // length of source string
        int n = t.length();  // length of target string

        // dp[i][j] will store the number of ways to match t[0...j-1] using s[0...i-1]
        vector <vector <long long>> dp(m + 1, vector<long long>(n + 1, 0));

        // Base case:
        // An empty target string "" can always be matched with any prefix of s in exactly 1 way: by deleting all characters.
        for (int i = 0; i <= m; i++){
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                /*
                 * If characters match (s[i-1] == t[j-1]):

                 * - We can include this character: dp[i-1][j-1]
                 
                 * - Or exclude it: dp[i-1][j]
                 * So, total = include + exclude
                 */

                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }

                /*
                 * If characters do not match, we can't include s[i-1] in match
                 * So, only option: exclude s[i-1] → carry forward dp[i-1][j]
                 */

                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The result is the number of ways to form entire string t from entire string s
        return dp[m][n];
    }
};

    