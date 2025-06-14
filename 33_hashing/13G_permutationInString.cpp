// permutationInString.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").


Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


Constraints:

1 <= s1.length, s2.length <= 1e4
s1 and s2 consist of lowercase English letters.

*/

class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        
        // If s1 is longer than s2, s2 cannot contain any permutation of s1
        if (s1.size() > s2.size()) return false;

        // Frequency count arrays for s1 and the current window in s2
        vector<int> s1Count(26, 0), windowCount(26, 0);

        int windowSize = s1.size();

        // Fill frequency array for s1
        for (char ch : s1) {
            s1Count[ch - 'a']++;
        }

        // Traverse s2 using a sliding window approach
        for (int i = 0; i < s2.size(); i++) {

            // Include the current character in the window count
            windowCount[s2[i] - 'a']++;

            // If window size exceeds s1 size, slide the window
            if (i >= windowSize) {
                // Remove the character that’s no longer in the window {i.e. wo i-windowSize wale ko bhagao...}
                windowCount[s2[i - windowSize] - 'a']--;
            }

            // Check if the current window has the same frequency count as s1
            if (windowCount == s1Count) return true;
        }

        // No permutation match found
        return false;
    }
};

/*

Hint 1
Obviously, brute force will result in TLE. Think of something else.

Hint 2
How will you check whether one string is a permutation of another string?

Hint 3
One way is to sort the string and then compare. But, Is there a better way?

Hint 4
If one string is a permutation of another string then they must have one common metric. What is that?

Hint 5
Both strings must have same character frequencies, if one is permutation of another.
Which data structure should be used to store frequencies?

Hint 6
What about hash table? An array of size 26?

*/
