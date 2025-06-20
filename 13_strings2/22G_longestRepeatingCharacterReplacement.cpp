// longestRepeatingCharacterReplacement.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given a string s and an integer k. 
You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get 
after performing the above operations.
 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.


Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 1e5
s consists of only uppercase English letters.
0 <= k <= s.length

*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();  // Get the size of the string

        // Initialize pointers i and j, and maxFreq to track the maximum frequency of a character
        int left = 0, right = 0, maxFreq = 0;  

        // HashMap to store the frequency of characters **within the window**
        unordered_map <char, int> mp;  

        // Variable to store the length of the longest valid substring
        int maxLen = -1;  

        // Iterate over the string with j as the right pointer of the window
        while (right < n) {
            // Increment the frequency of the character at position right
            mp[s[right]]++;  

            // Update the maxFreqmum frequency of any character in the window
            maxFreq = max(maxFreq, mp[s[right]]); 

            // If the length of the current window minus the frequency of the most frequent character
            // is greater than k, shrink the window from the left by moving the left pointer i
            if ((right - left + 1) - maxFreq > k) {
                // Decrease the frequency of the character at position i
                mp[s[left]]--;  

                // Move the left pointer to the right, shrinking the window
                left++;  
            }

            // Update the result with the length of the current valid window
            maxLen = max(maxLen, (right - left + 1));  

            // Move the right pointer to the next position
            right++;  
        }

        // Return the length of the longest valid substring
        return maxLen;  
    }
};
