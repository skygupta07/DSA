// substringWithConcatenationOfAllWords.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given a string s and an array of strings words. 
All the strings of words are of the same length. {minor detail given but useful {akash}}

A concatenated string is a string that exactly contains all the strings of any permutation 
of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", 
and "efcdab" are all concatenated strings. 

"acdbef" is not a concatenated string 
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

1 <= s.length <= 1e4
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.

*/

// substringWithConcatenationOfAllWords.cpp

#include <bits/stdc++.h>
using namespace std;

/*
Problem Summary:

You are given:
- ek string `s`
- ek vector of strings `words` (jaise ["foo", "bar"])

Goal:
- Find all starting indices in `s` jahan se ek substring shuru hoti ho
  jo `words` ke *kisi bhi permutation* ke concatenation ke barabar ho.
  
  Example:
  s = "barfoothefoobarman"
  words = ["foo", "bar"]
  Possible permutations: "foobar", "barfoo"
  Output: [0, 9] (s[0...5] = "barfoo", s[9...14] = "foobar")

Approach:
- Sliding window + HashMap frequency count
*/

// Leetcode-style class
class Solution {
public:

    // Function to find all starting indices of valid concatenated substrings
    vector <int> findSubstring(string s, vector<string> &words) {
        vector<int> ans;

        // Edge Case: agar string ya words empty hain toh answer bhi empty hoga
        if (words.empty() || s.empty()) return ans;

        int numWords = words.size();        // total number of words
        int wordLen = words[0].size();      // har word ka fixed length {given in question}
        
        int totalLen = numWords * wordLen;  // ek valid substring ka total length
        
        int strLen = s.length();            // input string ka length

        // wordCount map stores frequency of each word in 'words' vector
        unordered_map <string, int> wordCount;

        for (const string &word : words) wordCount[word]++;

        // We try to process multiple windows starting from different offsets
        // i = 0 to wordLen-1 tak => to handle every possible alignment
        // e.g. s = "_foo_bar_" => try starting from index 0, 1, 2
        for (int i = 0; i < wordLen; i++) {

            // Current window ka word count
            unordered_map <string, int> windowCount;  
            
            int left = i;                            // Window ka left boundary
            int right = i;                           // Window ka right boundary
            
            int count = 0;                           // Valid words ka count in current window

            // Right pointer ko move karte jao until end of string
            while (right + wordLen <= strLen) {

                // current word uthao of length 'wordLen' from 'right'
                string currWord = s.substr(right, wordLen);
                right += wordLen;  // Right window ko aage badhao

                // Agar currWord valid word hai (jo words[] mein diya gaya hai)
                if (wordCount.find(currWord) != wordCount.end()) {

                    windowCount[currWord]++;  // current word ka count badhao
                    count++;                  // total valid words ka count bhi badhao

                    // Agar kisi word ka count allowed limit se zyada ho gaya
                    // to window ko shrink karo jab tak condition satisfy ho
                    while (windowCount[currWord] > wordCount[currWord]) {
                        string leftWord = s.substr(left, wordLen);

                        windowCount[leftWord]--;
                        count--;
                        
                        left += wordLen;  // left pointer ko aage le jao {wordLen ki jump karwani padegi...}
                    }

                    // Agar window mein exactly 'numWords' words aa chuke hain
                    // that means ek valid substring mil gayi
                    if (count == numWords) {
                        ans.push_back(left);  // left index store karo as answer
                    }
                }

                // Agar currWord valid hi nahi hai
                else {
                    // Purana window reset karo
                    windowCount.clear();
                    count = 0;
                    left = right;  // new window start from right
                }
            }
        }

        return ans;
    }

};
