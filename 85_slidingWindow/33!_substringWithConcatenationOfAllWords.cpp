#include <bits/stdc++.h>
using namespace std;


/*
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation 
of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", 
and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string 
because it is not the concatenation of any permutation of words.

Return an array of the starting indices of all the concatenated substrings in s. 
You can return the answer in any order. 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo".
It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". 
It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

Explanation:

The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

 

Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.

*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (words.empty() || s.empty()) return ans;

        int numWords = words.size();
        int wordLen = words[0].size();

        int totalLen = numWords * wordLen;
        int strLen = s.length();

        unordered_map <string, int> wordCount;
        for (const string& word : words) wordCount[word]++;

        for (int i = 0; i < wordLen; i++) {
            unordered_map <string, int> windowCount;
            int left = i, right = i;
            int count = 0;

            while (right + wordLen <= strLen) {
                string currWord = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.find(currWord) != wordCount.end()) {
                    windowCount[currWord]++;
                    count++;

                    // If a word occurs more frequently than allowed, shrink the window
                    while (windowCount[currWord] > wordCount[currWord]) {
                        string leftWord = s.substr(left, wordLen);
                        windowCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // If the current window matches the words exactly
                    if (count == numWords) ans.push_back(left);
                }
                
                else {
                    // Reset the window when an invalid word is encountered
                    windowCount.clear();
                    count = 0;
                    left = right; // left pointer ko right pe le aaye..
                }

            }
        }
        return ans;
    }
};
