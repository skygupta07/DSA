// findLongestSpecialSubstringThatOccursThrice.cpp

/*

You are given a string s that consists of lowercase English letters.

A string is called special if it is made up of only a single character. 
For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.

Return the length of the longest special substring of s which occurs at least thrice, 
or -1 if no special substring occurs at least thrice.

A substring is a contiguous non-empty sequence of characters within a string.
 

Example 1:

Input: s = "aaaa"
Output: 2
Explanation: The longest special substring which occurs thrice is "aa": 
substrings "aaaa", "aaaa", and "aaaa".
It can be shown that the maximum length achievable is 2.

Example 2:

Input: s = "abcdef"
Output: -1
Explanation: There exists no special substring which occurs at least thrice. Hence return -1.


Example 3:

Input: s = "abcaba"
Output: 1
Explanation: The longest special substring which occurs thrice is "a": substrings "abcaba", "abcaba", and "abcaba".
It can be shown that the maximum length achievable is 1.
 

Constraints:

3 <= s.length <= 50
s consists of only lowercase English letters.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check if a substring of length >= x has a character repeating more than twice
    bool helper (const string &s, int n, int x){
        
        vector <int> freq(26, 0); // Frequency array to count occurrences of each character
        
        int p = 0; // Pointer to track the start of the current substring

        for (int i = 0; i < n; i++) {
            // Adjust the start pointer 'p' until s[p] matches s[i]
            while (s[p] != s[i]) p++;

            // If the current substring length (i - p + 1) >= x, count the character frequency
            if (i - p + 1 >= x) freq[s[i] - 'a']++;

            // If any character's count exceeds 2, return true
            if (freq[s[i] - 'a'] > 2) return true;
        }

        // If no character repeats more than twice for length >= x, return false
        return false;
        
    }

    // Function to find the maximum length of substring such that 
    // no character repeats more than twice in that substring
    int maximumLength(string s) {
        int n = s.length(); // Length of the string
        
        int lo = 1;         // Lower bound for binary search
        int hi = n;         // Upper bound for binary search

        // If the smallest length (1) fails the helper condition, return -1
        if (!helper(s, n, lo)) return -1;

        // Binary search to find the maximum valid length
        while (lo + 1 < hi) {

            int mid = lo + (hi - lo) / 2; // Midpoint of the current range

            if (helper(s, n, mid)) lo = mid;  // If valid, search for longer substrings
            
            else hi = mid;  // Otherwise, search for shorter substrings
        }

        // Return the maximum length found
        return lo;
    }
};
