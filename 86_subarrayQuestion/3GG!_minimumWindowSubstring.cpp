// minimumWindowSubstring.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t 
(including duplicates) is included in the window. If there is no such substring, 
return the empty string "".

The testcases will be generated such that the answer is unique.


Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.


Example 2:

Input: s = "a", t = "a"
Output: "a"

Explanation: The entire string s is the minimum window.


Example 3:    

Input: s = "a", t = "aa"
Output: ""

Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 10pow5
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?

*/

class Solution {
public:

    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        // Base case: If target is empty or longer than source, no valid window possible
        if (sLen == 0 || tLen == 0 || sLen < tLen) return "";

        // Frequency map for characters in string `t`
        // freq[ch] > 0 means this many of `ch` are still needed
        vector <int> freq(128, 0); // ASCII character set (0 to 127)

        // Populate the frequency map for string `t`
        for (char ch : t) freq[ch]++;
        

        int left = 0;           // Left boundary of sliding window
        int right = 0;          // Right boundary of sliding window

        int required = tLen;    // Total characters needed to match all of `t`

        int minLen = INT_MAX;   // Stores length of the minimum window found
        int minStart = 0;       // Start index of the best window

        // Begin sliding the window {now ab string s ke liye karenge...}
        while (right < sLen) {

            // string s ka character nikala...
            char ch = s[right];

            // If current character is still needed (positive frequency), reduce `required`
            if (freq[ch] > 0) required--;
            

            // Reduce frequency count regardless (helps track extra chars too)
            freq[ch]--;
            right++;

            // Now try to shrink the window from the left while it's still valid
            while (required == 0) {

                // Check if this window is smaller than previously found ones
                if (right - left < minLen) {
                    minLen = right - left;
                    
                    minStart = left;
                }

                // Shrink the window by moving `left` forward
                char leftChar = s[left];
                freq[leftChar]++; // Undo the effect of removing s[left]

                // If s[left] was in `t` and we now need it again, increase `required`
                if (freq[leftChar] > 0) {
                    required++;
                }

                left++; // Move the left end forward
            }
        }

        // If no valid window was ever found, return empty string 
        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen); 
        // abhi recently hi mai blank ho gaya tha.. {starting from this index mujhe itni length ka chahiye..}
        // actually ye substr function hi yaad nahi aa raha tha...
    }

};


/*

We're looking for the smallest substring of s that contains all characters 
(with correct frequency) from t.

Use the sliding window technique:


Expand the window to the right until it covers all characters from t.

Then, try to shrink it from the left to find the smallest valid window.
A frequency array helps track how many of each character are still required.
When the window contains all characters from t (required == 0), it’s a candidate.

*/



/*


Time Complexity:
O(sLen + tLen)

We scan t once to build the frequency array: O(tLen)
We expand and contract the sliding window using two pointers: 
O(sLen) in total (each character is processed at most twice).


📦 Space Complexity:
O(1) (Constant space)
Frequency array is of size 128 (for ASCII chars), which is constant.
No additional data structures grow with input size

*/