// circularString.cpp

#include <bits/stdc++.h>
using namespace std;


/*

A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
Words consist of only uppercase and lowercase English letters. 
Uppercase and lowercase English letters are considered different.

A sentence is circular if:

The last character of each word in the sentence is equal to the first character of its next word.
The last character of the last word is equal to the first character of the first word.
For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" 
are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" 
and "I like Leetcode" are not circular sentences.

Given a string sentence, return true if it is circular. Otherwise, return false.
 

Example 1:

Input: sentence = "leetcode exercises sound delightful"
Output: true

Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
- leetcode's last character is equal to exercises's first character.
- exercises's last character is equal to sound's first character.
- sound's last character is equal to delightful's first character.
- delightful's last character is equal to leetcode's first character.
The sentence is circular.


Example 2:

Input: sentence = "eetcode"
Output: true
Explanation: The words in sentence are ["eetcode"].
- eetcode's last character is equal to eetcode's first character.
The sentence is circular.


Example 3:

Input: sentence = "Leetcode is cool"
Output: false
Explanation: The words in sentence are ["Leetcode", "is", "cool"].
- Leetcode's last character is not equal to is's first character.
The sentence is not circular.
 

Constraints:

1 <= sentence.length <= 500
sentence consist of only lowercase and uppercase English letters and spaces.
The words in sentence are separated by a single space.
There are no leading or trailing spaces.

*/


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
