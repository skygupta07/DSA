// isomorphicStrings.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character
while preserving the order of characters. No two characters may map to the same character, 
but a character may map to itself.


Example 1:

Input: s = "egg", t = "add"
Output: true

Explanation:
The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.


Example 2:

Input: s = "foo", t = "bar"
Output: false

Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 
Constraints:

1 <= s.length <= 5 * 1e4

t.length == s.length
s and t consist of any valid ascii character.

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
                // wow I just discovered a new method to check the presence of element in a vector
                if (count(visited.begin() , visited.end(), charT) > 0){
                    return false;
                }

                visited[charS] = charT;     // mapping charS = charT
            }
            
            // if charS is visited , but not equal to charT then return false
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
        
        // Agar lengths equal nahi hain to obviously isomorphic nahi ho sakte
        if (t.length() != n) return false;
    
        // Dono taraf ka mapping track karne ke liye 2 unordered_maps
        unordered_map<char, char> mp1; // s -> t ka mapping
        unordered_map<char, char> mp2; // t -> s ka reverse mapping
    
        for (int i = 0; i < n; i++) {
            char ch1 = s[i];  
            char ch2 = t[i];  
    
            // agar ch1 map mai present h already but ch2 se map nahi h to bhai bekar h bhaiya...
            if (mp1.count(ch1) && mp1[ch1] != ch2) 
                return false; // agar map hai but kisi aur pe, then not isomorphic

            // Similarly, check ch2 ka mapping ch1 se hai ya nahi (reverse check)
            if (mp2.count(ch2) && mp2[ch2] != ch1) 
                return false;
    
            // Mapping store kar lo agar nahi hai to
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;

        }
    
        // Agar loop successfully complete ho gaya without contradiction implies that they are isomorphic
        return true;
    }
};

/*
    
size hi different h to return false...
    
string s ke characters par iterate karta hu.. and har char ke corresponding string t ke character
ko map kar deta hu....
    
and reverse mapping bhi karni padegi....
    

agar wo pehle se kisi aur character se map hoga to return false at that moment..
    
finally return true...

*/

