// longestPalindromicSubstring.cpp - - - very very very famous question

#include <bits/stdc++.h>
using namespace std;

/*

Given a string s, return the longest 
palindromic substring in s.


Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


*/

class Solution { // gives tle
private:

    bool isPalindrome(const string& str){
        int left = 0;
        int right = str.length()-1;

        while (left < right){
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }

public:

    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        int maxLen = 1;

         // Extracts the substring lefting at position 0 with length 1
        //   -> yaani ki ekdum first char yaha par...
        string maxStr = s.substr(0,1); 

        for (int i=0; i<n; i++){
            for (int j=i+maxLen; j<=n; j++){

                if (j-i > maxLen && isPalindrome(s.substr(i, j-i))){
                    maxLen = j-i;
                    maxStr = s.substr(i, j-i);
                }

            }
        }

        return maxStr;  
    }

};


class Solution {
public:

    // Function to expand around the center and find the length of the palindrome
    int expandFromCenter(string s, int i, int j) {
        int n = s.length();

        while ( (i >= 0) && (j < n) && (s[i] == s[j]) ) {
            i--;
            j++;
        }

        // Length of the palindrome 
        return j - i - 1;
    }


    string longestPalindrome(string s) {
        int n = s.length();

        // Edge case: if the string is empty or has only one character
        if (n <= 1) return s;
        
        // two pointers
        int left = 0; // left index of the longest palindrome
        int right = 0;   // right index of the longest palindrome

        for (int i = 0; i < n; i++) {

            // Check for odd-length palindromes (centered at a single character)
            int len1 = expandFromCenter(s, i, i);

            // Check for even-length palindromes (centered between two characters)
            int len2 = expandFromCenter(s, i, i + 1);

            // Find the maximum length from the two cases
            int len = max(len1, len2);

            // Update the left and right indices if a longer palindrome is found 
            // {right - left gives length of palindrome}

            if (len > right - left) {
                left = i - (len - 1) / 2;
                right = i + (len / 2);
            }

        }

        // Return the longest palindrome substring
        return s.substr(left, right - left + 1);

    }
};



/*
expand from center approach:

There are two cases for expanding around the center:

1. Expand around a single character (for odd-length palindromes)
2. Expand around two characters (for even-length palindromes)

From these two cases, the one with the maximum length will give the longest palindrome.

*/




