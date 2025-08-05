// countWordsWithGivenPrefix.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2

Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0

Explanation: There are no strings that contain "code" as a prefix.

*/



// I still remember forgetting substr(startingIdx, kitniLengthChahiye) function during my OA
class Solution {
public:

        int prefixCount(vector<string>& words, string pref) {
            int count = 0;
            int k = pref.length();

            for (int i = 0; i < words.size(); i++) {
                if (words[i].substr(0, k) == pref) count++;
            }
            
            return count;
        }
        
    };
    
class Solution {
public:

    bool isPrefix(string &pref, string &word){
        int n1 = pref.length();
        int n2 = word.length();

        if (n1 > n2) return false;

        for (int i=0; i<n1; i++) if (pref[i] != word[i]) return false;
        
        return true;
    }

    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        for (auto word : words){
            if (isPrefix(pref, word)) count++;
        }

        return count;
    }
};

