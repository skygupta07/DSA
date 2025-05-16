// numberOfSubstringsContainingAllThreeCharacters.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c 
are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters
 a, b and c are "aaacb", "aacb" and "acb". 

Example 3:

Input: s = "abc"
Output: 1
 
Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.

*/

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.length();
            vector<int> freq(3, 0); // Count occurrences of 'a', 'b', and 'c'
            int left = 0, count = 0;
    
            for (int right = 0; right < n; right++) {
                freq[s[right] - 'a']++; // Increase frequency of current character
    
                // While the current window contains at least one of each character
                while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                    count += (n - right); // All substrings from left to end are valid
                    freq[s[left] - 'a']--; // Shrink window from left
                    left++;
                }
            }
            return count;
        }
    };
    