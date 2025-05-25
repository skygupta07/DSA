#include <bits/stdc++.h>
using namespace std;

/*

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern 
and a non-empty word in s. 


Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"

Output: true

Explanation:

The bijection can be established as:

'a' maps to "dog".
'b' maps to "cat".
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"

Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"

Output: false



*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {

        // str ko word by word split karne ke liye
        stringstream ss(str);  
        string word;

        int idx = 0;  // pattern ke current index ke liye
        int n = pattern.length();  // pattern ka total length

        // pattern char -> word mapping
        unordered_map <char, string> mp; 

        // jo words already kisi character se map ho chuke hain
        unordered_set <string> usedWords; 


        // Jab tak words milte ja rahe hain aur pattern ke characters bache hain
        while (getline(ss, word, ' ') && idx < n){
            char currentChar = pattern[idx];

            // Agar current character ka pehle se mapping hai
            if (mp.find(currentChar) != mp.end()) {
                // Agar mapping ka word ab wala word se alag hai -> mismatch
                if (mp[currentChar] != word) return false; 
            }
            else {
                // Agar character ka mapping nahi hai lekin word already kisi aur char se map hai
                if (usedWords.count(word) > 0) return false;

                // Nayi mapping set kar do
                mp[currentChar] = word;
                usedWords.insert(word);
            }

            idx++;  // move to next pattern character
        }

        // Agar pattern characters finish nahi hue ya extra words the str mein
        return idx == n && ss.eof();
    }
};


/*

getline(ss, word, ' ');
This line is:

Taking input from a string stream ss
Extracting one word until a space ' ' is found
Storing that word into word


====> >> >

getline(ss, word, ' ');
Parameters:

ss → source stream
word → destination string to store result
' ' → delimiter (here space, so word by word)

*/



/*



We're looping through the words in the string using getline and stringstream. After the loop, we want to verify 2 things:

idx == size → We've matched all characters in pattern.
ss.eof() → We've also reached the end of the string stream, i.e., no extra words are left.


🔧 Full Form:
eof = End Of File

📖 Meaning in context of stringstream:
ss.eof() returns true only if:

We have read all characters from the stream
There is nothing left to read

*/