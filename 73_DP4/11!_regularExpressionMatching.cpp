// regularExpressionMatching.cpp

/*

Given an input string s and a pattern p, implement regular expression matching with support for
'.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).


Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".


Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. 
Therefore, by repeating 'a' once, it becomes "aa".


Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
 

Constraints:

1 <= s.length <= 20
1 <= p.length <= 20

s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.

It is guaranteed for each appearance of the character '*', 
there will be a previous valid character to match.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        // ✅ DP table banate hain jisme dp[i][j] batayega ki
        // s[0...i-1] tak ka substring pattern p[0...j-1] ke saath match karta hai ya nahi
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // ✅ Base Case: empty string "" and empty pattern "" match karte hain
        dp[0][0] = true;

        // ✅ Special handling for patterns like a*, a*b*, etc. jo empty string ko match kar sakte hain
        // Pattern ke starting mein agar '*' aata hai to uske pehle ka character remove karke check karo
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // ✅ DP table ko fill karna start karte hain
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // ⭐ Case 1: Agar pattern ka current character '*' hai
                if (p[j - 1] == '*') {
                    // Do options hain:

                    // 1️⃣ Zero occurrence: pattern ke last do characters ko ignore kar do
                    // e.g. s = "aab", p = "c*a*b" → "c*" ignore hoke "a*b" bacha
                    dp[i][j] = dp[i][j - 2];

                    // 2️⃣ One or more occurrence:
                    // Agar p[j-2] == s[i-1] ya '.' ho (jo kisi bhi character ko match karta hai),
                    // to s ke current character ko match maan ke aage badho
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }

                } else {
                    // ⭐ Case 2: Agar pattern ka current character normal hai ya '.'

                    // Match karne ke liye:
                    // - s[i-1] == p[j-1] hona chahiye ya
                    // - p[j-1] == '.' ho (wildcard)
                    // - Plus, previous subproblem dp[i-1][j-1] bhi true hona chahiye
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }

        // ✅ Final answer last cell me hoga: kya poora s and p match karte hain
        return dp[m][n];
    }
};

