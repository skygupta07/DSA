// ransomNote.cpp


#include <bits/stdc++.h>
using namespace std;

/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

*/

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) { // O(m+n)
            unordered_map <char,int> mp;    // to store the frequency of each character...
    
            for (char ch: magazine){
                if (mp.find(ch) == mp.end()){   // if the incoming is already not in the map then include it..
                    mp[ch] = 1;
                }else mp[ch]++;     // if already there then increase its 
            }
            // now iterate through ransomNote and check each character count there...
            for (char ch: ransomNote){
                if (mp.find(ch) != mp.end() && mp[ch]>0){   // if character present then decrease freq.
                    mp[ch]--;
                }else{
                    return false;
                }
            }
            return true; 
        }
    };