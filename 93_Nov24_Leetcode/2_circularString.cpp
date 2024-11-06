#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isCircularSentence(string sentence){
        stringstream ss(sentence);
        string word, prevWord;
        
        // Get the first word to initialize the circular comparison
        ss >> prevWord; // leetcode
        string firstWord = prevWord;   // copy store karke rakh liya for future use.
        
        while (ss >> word) {
            // Check if the last char of prevWord matches the first char of current word
            if (prevWord.back() != word.front()) {
                return false;
            }
            prevWord = word; // Update prevWord to the current word
        }
        // yaha tak aagya matlab beech wale saare condition theek honge.... bas ab wo last aur 
        // first wala aur check kar lo...
        // Check if the last char of the last word matches the first char of the first word
        return prevWord.back() == firstWord.front();
    }
};
