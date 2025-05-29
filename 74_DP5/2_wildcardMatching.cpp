// wildcardMatching.cpp

// chan chan badle tohre mijaj rajau...



/*
Given an input string (s) and a pattern (p), 
implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".


Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.


Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            int s_len = s.length(); 
            int p_len = p.length(); 
            
            // Edge case: if pattern is empty, it matches only an empty string
            if (p_len == 0) return s_len == 0;
            
            // Edge case: if pattern is just "*", it can match any string (including empty)
            if (p == "*") return true;
            
            // Create a DP table where dp[i][j] represents if `s[0..i-1]` matches `p[0..j-1]` - sabse main line yahi h ...
            // think deeper inside it as much as you can here....
            // jis pattern mai question mai bol rakha h ussi pattern mai humne bhi socha exactly.. ussi pattern mai..

            vector <vector <bool>> dp(s_len + 1, vector<bool> (p_len + 1, false));

            dp[0][0] = true; // Empty string matches an empty string
    
            // Fill the first row: pattern containing only '*' can match an empty string
            for (int j = 1; j <= p_len; j++) {
                if (p[j - 1] == '*') {
                    dp[0][j] = dp[0][j - 1]; // '*' can represent an empty sequence
                }
            }
    
            // Iterate through the string `s` and pattern `p`
            for (int i = 1; i <= s_len; ++i) {
                for (int j = 1; j <= p_len; ++j) {

                    if (p[j - 1] == '*') { 
                        // '*' can either:
                        // - Represent an empty sequence (dp[i][j - 1])
                        // - Represent any character (dp[i - 1][j])
                        dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                    } 

                    else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                        // '?' can match any single character
                        // If current characters match, inherit previous match result
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    
                }
            }
    
            // Final answer: does full `s` match full `p`
            return dp[s_len][p_len];
        }
    };
    