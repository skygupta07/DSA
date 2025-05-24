#include <bits/stdc++.h>
using namespace std;

/*

Given a string s and a dictionary of strings wordDict, 
return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.


Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

*/

void f(const string &s, int idx, string temp, unordered_set<string> &st, vector<string> &ans) {
    if (idx == s.size()) {  // If we've reached the end of the string
        temp.pop_back();    // Remove the trailing space
        ans.push_back(temp);  // Add the valid sentence to the result
        return;
    }

    // Loop through possible prefixes starting from idx
    for (int i = idx; i < s.size(); i++) {
        string current = s.substr(idx, i - idx + 1);  // Current substring

        if (!st.count(current)) continue;  // If the substring is not in the dictionary, skip it

        // Recurse with the remaining part of the string
        f(s, i + 1, temp + current + " ", st, ans);
    }
}

vector <string> wordBreak(string &s, vector<string> &dictionary) {
    string temp = "";
    vector<string> ans;
    unordered_set<string> st(dictionary.begin(), dictionary.end());  // Efficient set initialization

    f(s, 0, temp, st, ans);

    return ans;
}
