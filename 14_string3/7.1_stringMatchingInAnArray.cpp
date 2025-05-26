// stringMatchingInAnArray.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an array of string words, return all strings in words that are a substring of another word. 
You can return the answer in any order.


Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.


Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".



Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
All the strings of words are unique.

*/

class Solution {
public:
    // Helper function to compute the LPS array using the KMP algorithm
    vector<int> kmp(string s){

        vector<int> lps(s.length(), 0); // LPS array to store the longest prefix which is also a suffix

        for (int i = 1; i < s.length(); i++) {
            int prevIdx = lps[i - 1];

            // Adjust prevIdx if characters do not match
            while (prevIdx > 0 && s[i] != s[prevIdx]) {
                prevIdx = lps[prevIdx - 1];
            }

            // Update lps[i] if characters match
            if (s[i] == s[prevIdx]) {
                lps[i] = prevIdx + 1;
            } else {
                lps[i] = 0;
            }
        }

        return lps;
    }


    // Function to check if the pattern exists in the given string
    bool isSubstring(string pattern, string str) {
        
        string combined = pattern + "#" + str; // Combine pattern and str with a delimiter
        
        vector<int> lps = kmp(combined); // Compute LPS for the combined string

        for (int i = pattern.size() + 1; i < lps.size(); i++) {
            if (lps[i] == pattern.size()) {
                return true; // Pattern found as a substring
            }
        }

        return false; // Pattern not found
    }

    // Main function to find words that are substrings of other words
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;

        // Check each word against every other word
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && isSubstring(words[i], words[j])) {
                    result.push_back(words[i]);
                    break; // No need to check further if one match is found
                }
            }
        }

        return result;
    }
};
