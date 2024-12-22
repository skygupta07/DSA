#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map <string, vector <string> > mp;

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

