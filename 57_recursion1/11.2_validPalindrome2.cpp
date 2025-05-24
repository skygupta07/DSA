// validPalindrome2.cpp


/*

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true


Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.


Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool isPalindrome(string s, int i, int j){
        while (i < j){
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }


    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;

        while (i < j){
            if (s[i] == s[j]){
                i++;
                j--;
            }

            if (s[i] != s[j]){
                return ( isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1) );
            }
        }
        return true;
    }

};



/*
only single character ko skip kar sakte h bas..theek h 
using two pointer karo 
if (s[left] == s[right]) simply left++, right--;

if both characters are not equal then it could be possible ki i + 1, j  
 se lekar j tak palindrome ban jaye ya phir i, j - 1 tak ban jaye..
*/