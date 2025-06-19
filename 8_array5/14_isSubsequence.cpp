// isSubsequence.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some
(can be none) of the characters without disturbing the relative positions of the remaining characters.
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).


Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true


Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false


*/

class Solution {
public:
    bool isSubsequence(string s, string t){
        int i = 0; 
        int j = 0;

        int m = s.length();
        int n = t.length();
        
        // string s to be of min length go traversing over both the strings 
        // if both the characters are same then i++; and j++; else only j++;
        // agar last mai i has reached till end means it is subsequence...else return false...
        // while mai and laga ke dono condition if anyone of the condition fails then loop not executed

        // or simply while (i<m && j<n)

        while(i<=m-1 && j<=n-1){
            if (s[i] == t[j]) {i++; j++;}
            else{
                j++;
            }
        }
        // loop se bahar aa jaega agar successfully choti string mil jae.. 
        // ya phir...badi wali string ko bhi cross kar gaya...
        
        if (i == m) return true;  // loop breaking condition
        else return false;
    }
};
