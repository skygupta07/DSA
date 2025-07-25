#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestSubstring(string s, int k) {
            int n = s.length();
    
            // Base case: If the string is empty or smaller than k, no valid substring exists
            if (n == 0 || n < k) return 0;
    
            // If k is 1, every character in the string is a valid substring
            if (k <= 1) return n;
    
            // Step 1: Count frequency of each character in the string
            unordered_map<char, int> mp;
            for (char ch : s) mp[ch]++;
    
            int left = 0;
            
            // Step 2: Find the first character that appears less than k times
            while (left < n && mp[s[left]] >= k) left++;
    
            // If the entire string is valid (all characters appear at least k times), return its length
            if (left >= n - 1) return left;
    
            // Step 3: Recursively solve for the left part before the invalid character
            int l1 = longestSubstring(s.substr(0, left), k);
    
            // Move past the invalid characters
            while (left < n && mp[s[left]] < k) left++;
    
            // Step 4: Recursively solve for the right part after skipping invalid characters
            int l2 = left < n ? longestSubstring(s.substr(left), k) : 0;
    
            // Step 5: Return the maximum valid substring length found
            return max(l1, l2);
        }
    };
    