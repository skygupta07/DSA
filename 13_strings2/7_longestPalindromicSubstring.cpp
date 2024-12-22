#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Function to expand around the center and find the length of the palindrome
    int expandFromCenter(string s, int i, int j) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        // Length of the palindrome
        return j - i - 1;
    }

    string longestPalindrome(string s) {
        // Edge case: if the string is empty or has only one character
        if (s.empty()) return "";
        if (s.length() == 1) return s;
        
        int start = 0; // Start index of the longest palindrome
        int end = 0;   // End index of the longest palindrome

        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindromes (centered at a single character)
            int len1 = expandFromCenter(s, i, i);
            // Check for even-length palindromes (centered between two characters)
            int len2 = expandFromCenter(s, i, i + 1);

            // Find the maximum length from the two cases
            int len = max(len1, len2);

            // Update the start and end indices if a longer palindrome is found
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        // Return the longest palindrome substring
        return s.substr(start, end - start + 1);
    }
};


/*
expand from center approach:

There are two cases for expanding around the center:
1. Expand around a single character (for odd-length palindromes)
2. Expand around two characters (for even-length palindromes)

From these two cases, the one with the maximum length will give the longest palindrome.
*/


