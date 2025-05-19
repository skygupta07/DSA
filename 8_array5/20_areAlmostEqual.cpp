#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; // Case when strings are already equal
        
        vector <int> diff;  // will store the index of characters wherever there will be mismatch
        
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }
        
        // There should be exactly 2 mismatched positions for a single swap to work
        if (diff.size() != 2) return false;
        
        // Check if swapping these positions makes them equal
        return (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]);
    }
};
