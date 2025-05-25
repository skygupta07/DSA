// longestHappyPrefix_KMP.cpp

#include <bits/stdc++.h>
using namespace std;


/*

A string is called a happy prefix if is a non-empty prefix which is also a sufffix (excluding itself).
Given a string s, return the longest happy prefix of s.

Return an empty string "" if no such prefix exists.
 

Example 1:

Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), 
and sufffix ("l", "el", "vel", "evel"). The largest prefix which is also sufffix is given by "l".


Example 2:

Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also sufffix. 
They can overlap in the original string.
 

Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.

*/

class Solution {
public:
    string longestPrefix(string s) {
        int pref = 0;            // 'pref' tracks the current prefix length we're matching
        int suff = 1;            // 'suff' scans the string from index 1
        
        vector <int> lps(s.length(), 0);  // LPS array to store longest prefix-sufffix lengths

        // Build LPS array (standard KMP preprocessing)
        while (suff < s.length()) {
            
            if (s[suff] == s[pref]) {
                // If characters match, increment prefix length
                lps[suff] = pref + 1;
                
                pref++;
                suff++;
            } 

            else {
                if (pref == 0) {
                    // No match and no prefix so far
                    lps[suff] = 0;
                    suff++;
                } 
                else {
                    // Jump back to previous prefix value
                    pref = lps[pref - 1];
                }
            }
            
        }

        // The last value in lps gives the length of the longest prefix which is also sufffix
        return s.substr(0, pref);  // Return the actual prefix substring
    }
};
