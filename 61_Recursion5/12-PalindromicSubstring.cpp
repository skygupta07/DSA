// palindromicSubstring.cpp

/*

Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

*/


#include <bits/stdc++.h>
using namespace std;


// wrong approach.....
class Solution {
public:

    void generateSub(string &s, vector <string> substr, string &auxStr, int idx){
        int n = s.length();

        if (idx == n){
            substr.push_back(auxStr);
            return; // imp
        }

        generateSub(s,substr,auxStr,idx+1); // ek baar normal call
        auxStr.push_back(s[idx]); // ek baar temp/aux mai push karke call 
        generateSub(s, substr, auxStr, idx + 1); // phir again wahi normal call
    }

    bool isPalindrome(string &str){
        int i = 0;
        int j = str.length() - 1;
        
        while (i<=j){
            if (str[i] == str[j]){
                i++;
                j--;
            }
            else return false;   
        }
        return true;
    }

    int countSubstrings(string s){
        int count = 0;
        int n = s.length();
        vector <string> substr(pow(2,n), "");

        
        string auxStr;
        generateSub(s, substr, auxStr , 0);

        for (int i=0; i<substr.size(); i++){
            if (isPalindrome(substr[i])) count++;
        }

        return count;

    }
};

/*
int count
generate substring -> recursion take it don't take it...
for single length string -> count + = length
generate other substrings and apply check of palindrome if palindrome then count++

*/



class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while (i<j){
            if (s[i] == s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }

    int countSubstrings(string s){ // O(n^3)
        int n = s.length();
        int count = 0;
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                if ( isPalindrome(s, i, j)) count++;
            }
        }
        return count;
    }
};




class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int even = palindromeCount(s, i, i + 1);
            int odd = palindromeCount(s, i, i);
            ans += even + odd;
        }
        return ans;
    }

    int palindromeCount(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
            ++count;
        }
        return count;
    }
};