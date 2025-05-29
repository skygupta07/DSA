// shortestCommonSupersequence.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.
If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) 
results in the string s.
 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"

Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.


Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"

*/



class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int m = str1.length(), n = str2.length();

        // Step 1: Create DP table for Longest Common Subsequence (LCS)
        // lcs[i][j] = length of LCS of str1[0..i-1] and str2[0..j-1]
        vector<vector<int>> lcs(m + 1, vector<int>(n + 1, 0));

        //  Fill LCS table using bottom-up approach
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // If characters match, increase LCS length
                if (str1[i - 1] == str2[j - 1]) lcs[i][j] = 1 + lcs[i - 1][j - 1];

                // Else pick max from top or left
                else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }

        // Step 2: Reconstruct Shortest Common Supersequence (SCS) from LCS table
        int i = m, j = n;
        string result = "";

        while (i > 0 && j > 0) {

            // Case 1: Same character in both strings — add once
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--, j--;
            }

            // Case 2: Characters differ — choose direction with longer LCS
            else if (lcs[i - 1][j] > lcs[i][j - 1]) {
                result += str1[i - 1]; // Pick from str1
                i--;
            } 
            
            else {
                result += str2[j - 1]; // Pick from str2
                j--;
            }
        }

        // Step 3: Add remaining characters (if any)
        while (i > 0) result += str1[i-- - 1]; // str1 ke remaining
        while (j > 0) result += str2[j-- - 1]; // str2 ke remaining

        //  Step 4: Reverse the result since we built it backward
        reverse(result.begin(), result.end());

        return result;
    }
};
