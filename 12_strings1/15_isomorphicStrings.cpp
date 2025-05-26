// isomorphicStrings

#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving
the order of characters. 

No two characters may map to the same character, but a character may map to itself
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false; // length check

        vector <char> visited(128 , 0); // initialise data structure

        for (int i=0; i<s.length(); i++){   // iterate through characters
            char charS = s[i];
            char charT = t[i];

            if (visited[charS] == 0){   // charS not visited yet
                
                // but corresponding charT has been visited -> return false
                if (count(visited.begin() , visited.end(), charT) > 0){
                    return false;
                }
                visited[charS] = charT;     // mapping charS = charT
            }
            else if (visited[charS] != charT){
                return false;
            }
        }

        return true;
    }
};


class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            int n = s.length();
            if (t.length() != n) return false;
    
            unordered_map <char, char> mp1;
            unordered_map <char, char> mp2;
    
            for (int i=0; i<n; i++){
                char ch1 = s[i];
                char ch2 = t[i];
    
                if (mp1.count(ch1) && mp1[ch1] != ch2) return false;
                if (mp2.count(ch2) && mp2[ch2] != ch1) return false;
    
                mp1[ch1] = ch2;
                mp2[ch2] = ch1;
            }
    
            return true;
        }
    };
    
    
    /*
    
    size hi different h to return false...
    
    string s ke characters par iterate karta hu.. and har char ke corresponding string t ke character
    ko map kar deta hu....
    
    and reverser mapping bhi karni padegi....
    
    
    agar wo pehle se kisi aur character se map hoga to return false at that moment..
    
    finally return true...
    */

