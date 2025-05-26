#include <bits/stdc++.h>
using namespace std;

/*

Given a binary string s, return the number of non-empty substrings 
that have the same number of 0's and 1's, and all the 0's and all the 1's 
in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

 
Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive
 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.


Example 2:

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" 
that have equal number of consecutive 1's and 0's. 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.

*/

// again pure dsa Or Rattne wala algo ??

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;        // Final answer to store number of valid binary substrings
        
        int previous = 0;   // Length of previous group (of 0s or 1s)
        int current = 1;    // Length of current group (starts with 1 since s[0] already counted)

        // Loop starts from second character
        for(int i = 1; i < s.size(); i++) {
            
            if(s[i] == s[i-1]) {
                // Current char same as previous one → extend current group
                current++;
            } 
            
            else {
                // Character changed → start of new group
                previous = current;  // Save current group length as previous
                current = 1;         // Reset current group count
            }

            // Agar current group size ≤ previous group size → valid substring possible
            if(current <= previous) ans++;
        }

        return ans;
    }
};
