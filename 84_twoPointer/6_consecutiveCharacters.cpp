// consecutiveCharacters.cpp

/*

The power of the string is the maximum length of a non-empty substring 
that contains only one unique character.

Given a string s, return the power of s.

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.


Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.


Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int maxPower(string s) {
        int n = s.length();

        // very famous pattern 
        int currLen = 1;
        int maxLen = 1;

        for (int i=1; i<n; i++){
            // jab tak same aa rahe h currLen ko increase kar 
            // and globally maxLen variable ko maximize bhi karta chal....
            // aur agar kisi bhi point par same nahi milte.. to phir reset kar do..
            if (s[i] == s[i-1]){
                currLen++;
                maxLen = max(maxLen, currLen);
            }
            // reset again to min. possible length
            else currLen = 1;
        }

        return maxLen;
    }
};

// two pointers - optimised...