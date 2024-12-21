#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
using namespace std;

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

vector<string> wordBreak(string &s, vector<string> &dictionary) {
    string temp = "";
    vector<string> ans;
    unordered_set<string> st(dictionary.begin(), dictionary.end());  // Efficient set initialization

    f(s, 0, temp, st, ans);

    return ans;
}
