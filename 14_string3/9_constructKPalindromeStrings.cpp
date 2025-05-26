// constructKPalindromeStrings.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a string s and an integer k, 
return true if you can use all the characters in s to construct non-empty k palindrome strings 
or false otherwise.
 

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"


Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.


Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
 

Constraints:

1 <= s.length <= 10pow5
s consists of lowercase English letters.
1 <= k <= 10pow5

*/


class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();

        // single length bhi possible nahi ho payega. to kiss bat ka palindrome
        if ( k > n) return false;


        sort(s.begin(), s.end());   //similar chars saath mai aa jayenge..
        
        int oddCount = 0;

        for (int i=0; i<s.length();){
            char curr = s[i];
            int count = 0;

            while (i <= n-1 && s[i] == curr){
                count++;
                i++;
            }

            if (count % 2 != 0) oddCount++;
        }
        
        return oddCount <= k; 
    }
};