#include <bits/stdc++.h>
using namespace std;

/*

Given a sentence that consists of some words separated by a single space, and a searchWord, 
check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. 
If searchWord is a prefix of more than one word, return the index of the first word (minimum index). 
If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.


Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.


Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.


Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.


*/


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
        string word;    // stringstream ke baad agar aapne string temp/word   ye nahi likha to kya likha..
        

        // arey yrr magar stringstream use karne se ab mai index kaise maintain karunga ??
        // abey saale manually bhi to maintain kar sakta h ...🥲
        
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
