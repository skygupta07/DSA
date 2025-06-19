#include <bits/stdc++.h>
using namespace std;

/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.


Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.


Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.


Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 1e4
s consists of only English letters and spaces ' '.
There will be at least one word in s.


*/

class Solution {
public:
    int lengthOfLastWord(string s){
        // maintain a tail pointer which starts from the last of string if we encounter a space then searh for 
        // go left until space comes again and again...
        
        // if encounter a char in first go then start counting it....unless you encountered a space...
        // always apply that you don't cross the stirng...
        int count = 0;

        int tail = s.length() - 1; // tail as a pointer to last index
        
        // remove trailing spaces..
        while ( tail >= 0 && s[tail] == ' ') tail--;        // tail >= 0   ye limit na cross karne wali condition to
                                                            // while loop mai lagana hi padta hai hai..
        while (tail >= 0 && s[tail] != ' '){
            tail--;
            count++;
        }
        
        return count; 
    }
};

// using stringstream

class Solution {
public:

    int lengthOfLastWord(string s) {
        stringstream ss(s);  // Input string ko stream me convert kar rahe hain (space ke basis par words extract karne ke liye)
        string temp;         // Temporary variable to hold each word {stringstream ke baad string temp likhna bahut jaruri..}
        
        string lastWord;     // Ye store karega last valid word (non-space)

        while (ss >> temp)   // Jab tak stream me words milte rahe
            lastWord = temp; // Har word ko lastWord me store karte raho (last word automatically mil jayega)
        
        return lastWord.length();  // Last word ka length return karo
    }

};

