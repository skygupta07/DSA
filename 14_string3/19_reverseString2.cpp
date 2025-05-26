// reverseString2.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string reverseStr(string s, int k) {
            int n = s.length();
    
            for (int i = 0; i < n; i += 2 * k) {
                // Reverse first k characters in every 2k segment
                int end = min(i + k, n);  // Ensure we don't go out of bounds
                reverse(s.begin() + i, s.begin() + end);
            }
    
            return s;
        }
    };
    