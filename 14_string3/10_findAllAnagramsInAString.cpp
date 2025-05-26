// findAllAnagramsInAString.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given two strings s and p, 
return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order. 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".


Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.

*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length(); // Window size
        
        vector <int> ans;

        // Edge case: if p's length is greater than s's length, no anagrams are possible
        if (n < k) return ans;

        // Frequency maps for p and the current window in s
        vector <int> pFreq(26, 0), sFreq(26, 0);

        // Populate frequency map for p
        for (char ch : p) pFreq[ch - 'a']++;

        // Sliding window over s
        for (int i = 0; i < n; i++) {
            // Add the current character to the window
            sFreq[s[i] - 'a']++;

            // Remove the leftmost character from the window if its size exceeds k
            if (i >= k) sFreq[s[i - k] - 'a']--;

            // Compare frequency maps: if they match, it's an anagram
            if (pFreq == sFreq) ans.push_back(i - k + 1);
        }

        return ans;
    }
};
