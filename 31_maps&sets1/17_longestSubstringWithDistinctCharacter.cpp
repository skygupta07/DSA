// longestSubstringWithDistinctCharacter.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given a string s, find the length of the longest substring with all distinct characters. 

Examples:

Input: s = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest substring with all distinct characters.


Input: s = "aaa"
Output: 1
Explanation: "a" is the longest substring with all distinct characters.


Input: s = "abcdefabcbb"
Output: 6
Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.


Constraints:
1<= s.size()<=3*104
All the characters are in lowercase.


*/

class Solution {
public:
    int longestUniqueSubstr(string &s) {
        int n = s.length();

        // Stores the last index of each character*
        unordered_map <char, int> mp; 

        int maxLen = 0; // Maximum length of unique substring
        int left = 0;   // Left pointer of the sliding window
        
        for (int right = 0; right < n; right++) {
            
            // If the character is already in the map, move the left pointer && wo right wala element 
            //  jo consider kar rahe h wo valid window mai hona bhi to chahiye..(imp)
            if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) {
                left = mp[s[right]] + 1; // Update the left pointer to skip the duplicate
            }
            
            // Update the last seen index of the character
            mp[s[right]] = right; //imp
            
            // Update the maximum length
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;

    }

};
