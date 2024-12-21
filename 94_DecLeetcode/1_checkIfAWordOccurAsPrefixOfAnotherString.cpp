#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPrefix(string s, string t) {
        if (s.length() > t.length()) return false; // Ensure `t` is long enough
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence); // Use stringstream to tokenize the sentence
        string word;
        int index = 1; // Start counting words from 1

        while (ss >> word) { // Extract words one by one
            if (isPrefix(searchWord, word)) {   // searchword should be prefix of word
                return index; // Return the 1-based index if prefix matches
            }
            index++;
        }

        return -1; // Return -1 if no word matches
    }
};
