#include <bits/stdc++.h>
using namespace std;

/*

A sentence is a string of single-space separated words where each word consists 
only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, 
and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. 
You may return the answer in any order.

 

Example 1:
Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]

Explanation:
The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]

 

Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.


*/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // we need to find unique occurences
        string s = s1 + " " + s2; // tumhare kaminepan ke hum gulam ho gaye...
        stringstream str(s);

        string tmp; // arey bkl koi jhola ya container to chahiye hi hoga na ... wo jo incoming strings ...
        // jo str se aa rahi ho ... usko store karne ke liye...

        // store all words from s
        unordered_map <string, int> mp;
        

        while(str >> tmp){    // stringstream ❌ cin ka bhai... ✅
            mp[tmp]++;
        }

        // check unique means single count
        vector <string> ans;

        for(const auto &[word, freq] : mp){ // auto it=mp.begin();it<mp.end();it++

            // val.first = apple, val.second = 2
            // if single frequency
            if(freq == 1){
                ans.emplace_back(word); // can use push_back also                
            }
        }
        return ans;
    }
};