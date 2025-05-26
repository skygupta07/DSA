#include <bits/stdc++.h>
using namespace std;


/*

Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string 
with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde". 

Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")


Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".


Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
 

Constraints:

3 <= s.length <= 105
s consists of only lowercase English letters.

*/


class Solution {
public:

    int countPalindromicSubsequence(string inputString){

        // Arrays to store the minimum and maximum occurrences of each character in the input string
        vector <int> minExist(26, INT_MAX);
        vector <int> maxExist(26, INT_MIN);

        // Populate minExist and maxExist arrays
        for(int i = 0; i < inputString.size(); i++) {

            int charIndex = inputString[i] - 'a';

            minExist[charIndex] = min(minExist[charIndex], i);
            maxExist[charIndex] = max(maxExist[charIndex], i);
        }

        // Variable to store the final count of unique palindromic subsequences
        int uniqueCount = 0;
        
        // Iterate over each character in the alphabet
        for (int charIndex = 0; charIndex < 26; charIndex++) {

            // Check if the character has occurred in the input string
            if (minExist[charIndex] == INT_MAX || maxExist[charIndex] == INT_MIN) {
                continue; // No occurrences, move to the next character
            }

            // Set to store unique characters between the minimum and maximum occurrences
            unordered_set <char> uniqueCharsBetween;

            // Iterate over the characters between the minimum and maximum occurrences
            for (int j = minExist[charIndex] + 1; j < maxExist[charIndex]; j++) {
                uniqueCharsBetween.insert(inputString[j]);
            }

            // Add the count of unique characters between the occurrences to the final count
            uniqueCount += uniqueCharsBetween.size();
        }

        // Return the total count of unique palindromic subsequences
        return uniqueCount;
    }
};

/*
store the first and last occurence index of each character...

now iterate over each charcter in string s, 
and see if the index of ith character is greater than first and last of any of the character 
in occurences ... count this ...

*/