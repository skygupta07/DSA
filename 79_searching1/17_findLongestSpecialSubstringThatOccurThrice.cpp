#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check if a substring of length >= x has a character repeating more than twice
    bool helper (const string &s, int n, int x){
        vector<int> cnt(26, 0); // Frequency array to count occurrences of each character
        int p = 0; // Pointer to track the start of the current substring

        for (int i = 0; i < n; i++) {
            // Adjust the start pointer 'p' until s[p] matches s[i]
            while (s[p] != s[i]) p++;

            // If the current substring length (i - p + 1) >= x, count the character frequency
            if (i - p + 1 >= x) cnt[s[i] - 'a']++;

            // If any character's count exceeds 2, return true
            if (cnt[s[i] - 'a'] > 2) return true;
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
            if (helper(s, n, mid)) 
                lo = mid;  // If valid, search for longer substrings
            else 
                hi = mid;  // Otherwise, search for shorter substrings
        }

        // Return the maximum length found
        return lo;
    }
};
