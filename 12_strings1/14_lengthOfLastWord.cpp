#include <bits/stdc++.h>
using namespace std;

/*
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

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


