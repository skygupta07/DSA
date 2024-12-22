#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving
the order of characters. No two characters may map to the same character, but a character may map to itself
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
         unordered_map<char, char> mp, mp2;
        for (int i=0; i<s.length(); ++i) {
            if (mp[s[i]] && mp[s[i]]!=t[i]) return false;
            if (mp2[t[i]] && mp2[t[i]]!=s[i]) return false;
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};