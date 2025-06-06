// wordBreak.cpp

#include <bits/stdc++.h>
using namespace std;

/*
Given a string s and a dictionary of strings wordDict, 
return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.


Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();  // Get the length of the string s

        vector <bool> dp(n + 1, false);  // Initialize a dp array of size n+1 with false

        dp[0] = true;  // Base case: an empty substring can always be segmented

        // Outer loop: i represents the endpoint of the current substring s[0:i]
        for (int i = 0; i <= n; i++) {
            // Inner loop: j represents the start of the current substring s[j:i]
            for (int j = 0; j < i; j++) {

                // Check if s[0:j] can be segmented and s[j:i] is in wordDict
                if (dp[j]) {  // If dp[j] is true, then s[0:j] can be segmented
                    
                    // Check if s[j:i] exists in wordDict
                    if (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                        dp[i] = true;  // Mark dp[i] as true since s[0:i] can be segmented
                        break;  // Exit the inner loop early as we found a valid segmentation
                    }

                }
            }
        }

        return dp[s.size()];  // Return whether the entire string s can be segmented
    
    }
};
