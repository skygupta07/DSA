#include <bits/stdc++.h>
using namespace std;

/*

Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.
 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

 
Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.


*/

class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map <string, vector <string> > mp;


        // waah kya kaarigari h ...in haatho ko to kaat dena chahiye 🥲
        for (auto s: strs){
            string originalString = s;
            sort(s.begin() , s.end());
            
            mp[s].push_back(originalString);
        }

        for (auto [key, vectOfStrings]: mp){
            result.push_back(vectOfStrings);
        }

        return result;
    }
};

