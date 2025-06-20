// kmpAlgorithm.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Problem Title:
Find All Occurrences of a Pattern in a Text (KMP Algorithm)

Problem Statement:
You are given two strings:

pat (the pattern) and
txt (the text).

Your task is to return all starting indices in txt where pat appears as a substring.
The matching should be exact, and overlapping matches are allowed.

Input:
pat: a string of length m (1 ≤ m ≤ 1e5)
txt: a string of length n (1 ≤ n ≤ 1e5)
Both strings consist of lowercase English letters only.

Output:
Return a vector of integers representing the starting indices (0-based) 
where the pattern pat is found in txt.

If the pattern does not appear, return an empty vector.


Example 1:

Input:
pat = "ab"
txt = "ababcab"

Output:
[0, 2, 5]

Explanation:
The pattern "ab" appears at indices:

0 ("ab"abcab)
2 (ab"ab"cab)
5 (ababc"ab")


Example 2:

Input:
pat = "aaa"
txt = "aaaaaa"

Output:
[0, 1, 2, 3]

Explanation:
Overlapping matches of "aaa" are allowed:

Starts at 0: "aaa"
Starts at 1: "aaa"
Starts at 2: "aaa"
Starts at 3: "aaa"


Constraints:

1 <= pat.length, txt.length <= 1e5
Both strings consist of only lowercase letters 'a' to 'z'.


Follow-Up:
Can you solve this in O(n + m) time complexity?

Note: A brute-force approach using substr will give TLE for large inputs.


*/


// bruteFoce will give tle
class Solution { 
public:

    vector <int> search(string &pat, string &txt) {

        int n = txt.length();

        vector <int> ans;
        
        int k = pat.length();
        
        for (int left = 0; left <= n - k; left++) {

            if (txt.substr(left, k) == pat) {
                ans.push_back(left);
            }
        }
        
        return ans;
    }
};


// kmp

class Solution {
private:

    // Helper function to build the LPS (Longest Prefix Suffix) array
    void computeLPS(string &pat, int m, vector <int> &lps) {

        int len = 0;     // Length of the longest proper prefix which is also a suffix
        lps[0] = 0;      // Base case: the first character has no proper prefix/suffix

        int i = 1;       // Start checking from the second character
        
        while (i < m) {

            if (pat[i] == pat[len]) {
                // Characters match —> extend the current prefix
                len++;

                lps[i] = len;
                i++;
            } 
            
            else {

                if (len != 0) {
                    //  Backtrack to check for shorter prefix-suffix match
                    len = lps[len - 1];
                } 
                
                else {
                    // ❌ No match and no prefix to fall back to
                    lps[i] = 0;
                    i++;
                }
            }
        }

    }


public:

    // KMP Search: Find all starting indices of pat in txt
    vector <int> search(string &pat, string &txt) {

        int m = pat.length();
        int n = txt.length();
        
        // Preprocessing step: build the LPS array
        vector <int> lps(m, 0); 
        
        vector <int> ans;       // To store starting indices of matches

        computeLPS(pat, m, lps); // ⛏️ Build the prefix table

        int i = 0; // Pointer for txt
        int j = 0; // Pointer for pat

        while (i < n) {

            if (txt[i] == pat[j]) {
                // Characters match, move both pointers
                i++;
                j++;
            }

            if (j == m) {
                // Full match found or full pattern found in text
                ans.push_back(i - j); // i-j gives the starting index
                
                j = lps[j - 1];       // Backtrack using LPS to allow overlapping matches
            } 

            else if (i < n && txt[i] != pat[j]) {
                
                if (j != 0) {
                    // Mismatch but not at start — backtrack in pat
                    j = lps[j - 1];
                } 
                
                else {
                    // ❌ Mismatch at start — move txt pointer
                    i++;
                }
                
            }
        }

        return ans; // Return all match indices
    }

};


/*

LPS[i] tells us the length of the longest prefix of pat[0...i] which is also a suffix.
This avoids unnecessary re-checking of characters on mismatch.
Total time complexity is O(n + m) — very efficient for large strings.

*/


