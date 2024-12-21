#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // we need to find unique occurences
        string s = s1 + " " + s2;
        stringstream str(s);

        // store all words from s
        unordered_map <string,int> mp;
        string tmp;

        while(str>>tmp){    // stringstream cross cin ka bhai...
            mp[tmp]++;
        }

        // check unique means single count
        vector<string> ans;
        for(auto& val:mp){ // auto it=mp.begin();it<mp.end();it++

            // val.first = apple, val.second = 2
            // if single frequency
            if(val.second==1){
                ans.emplace_back(val.first); // can use push_back also                
            }

        }

        return ans;
    }
};