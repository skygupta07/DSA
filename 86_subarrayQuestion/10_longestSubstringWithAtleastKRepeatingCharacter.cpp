// longestSubstringWithAtleastKRepeatingCharacter.cpp

/*

Given a string s and an integer k, 
return the length of the longest substring of s such that the frequency of each character 
in this substring is greater than or equal to k.

if no such substring exists, return 0.


Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.


Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", 
as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:

1 <= s.length <= 1e4
s consists of only lowercase English letters.
1 <= k <= 1e5

*/



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
            unordered_map <char, int> mp;

            for (char ch : s) mp[ch]++;
    
            int left = 0;
            
            // Step 2: Find the first character that appears less than k times
            while (left < n && mp[s[left]] >= k) left++;
    
            // If the entire string is valid (all characters appear at least k times),
            //  return its length
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
    