// firstUniqueChar.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.


Example 1:

Input: s = "leetcode"
Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1

*/


// 26 January ❌ 26 size ka vector ✅

class Solution {
public:
    int firstUniqChar(string s){

        // to store the freq of characters..
        vector <int> freq(26,0);

        // har character par gaye...
        for (int i=0; i<s.length(); i++){

            char ch = s[i];
            // aur character ki frequency update kar di..
            freq[ch - 'a']++;
        }
        
        for (int i=0; i<s.length(); i++){
            // agar kisi bhi char ki frequency.. 1 h to uss index ko return kar do..
            if (freq[s[i] - 'a'] == 1) return i;

        }

        return -1;
    }
};

/*

smart use of ascii value
index find karne ka casual tarika is char - 'a'
// next loop mai vector mai bhi to corresponding mapping dekhni hogi...

*/

