#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Bitmask to represent the vowel parity
        unordered_map<int, int> mp;
        
        // Initial state, no vowels encountered, mask = 0
        mp[0] = -1;
        
        int mask = 0;
        int maxi = 0;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            // Update the mask based on the current character being a vowel
            if (ch == 'a') {
                mask ^= (1 << 0);
            } else if (ch == 'e') {
                mask ^= (1 << 1);
            } else if (ch == 'i') {
                mask ^= (1 << 2);
            } else if (ch == 'o') {
                mask ^= (1 << 3);
            } else if (ch == 'u') {
                mask ^= (1 << 4);
            }
            
            // If this mask has been seen before, the substring from the previous
            // occurrence to the current index has even vowel counts.
            if (mp.find(mask) != mp.end()) {
                maxi = max(maxi, i - mp[mask]);
            } else {
                // Otherwise, store the first occurrence of this mask
                mp[mask] = i;
            }
        }
        
        return maxi;
    }
};
