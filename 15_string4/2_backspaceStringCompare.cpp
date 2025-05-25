// backspaceStringCompare.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given two strings s and t, return true if they are equal when both are typed into empty text editors. 
'#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.


Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".


Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".


Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".


*/


class Solution {
public:

    bool backspaceCompare(string s, string t) {
        stack <char> stk1;
        stack <char> st2;

        for (auto ch : s){
            if (!stk1.empty() && ch == '#') stk1.pop();

            // agar kucch likha nahi h and khali pili backspace daba rahe ho to bhi kucch fayda nahi.. ignore maaro
            else if (stk1.empty() && ch == '#') continue;

            else stk1.push(ch);
        }

        for (auto ch : t){
            if (!st2.empty() && ch == '#' ) st2.pop();
            else if (st2.empty() && ch == '#') continue;
            else st2.push(ch);
        }

        return (stk1 == st2);

    }
};

/*
always remember when your are popping from stack then the stack should not be empty...
*/


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sf;
        string tf;

        // sach batau to mujhe abhi bhi viswas nahi ho rha ki string mai push_back()   aur pop_back() fn bhi hota h..
        for (auto ch : s){
            if (ch == '#'){
                if (!sf.empty()) sf.pop_back(); // rambaan
            }
            else sf.push_back(ch);
        }

        for (auto ch : t){
            if (ch == '#'){
                if (!tf.empty()) tf.pop_back();
            }
            else tf.push_back(ch);
        }

        return (sf == tf);
    }
};

/*
accha aap size declare nahi kar paa rahe to theek h string ke pop_back ki help lelo....

*/