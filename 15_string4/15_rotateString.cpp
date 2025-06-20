// rotateString.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given two strings s and goal, return true if and only if s can become goal 
after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.

*/



// pure brute force
class Solution {
public:

    bool rotateString(string s, string goal) {
        int n = s.length();
        string temp = s;

        vector <string> v;

        while (n--){
            char first = temp[0];   // take first character 
            temp.erase(0, 1);  // starting from the zeroth index ek element ko remove kar de..
            // ==== ki first character ko remove kar de...

            temp += first;  // append it at back

            v.push_back(temp);  // store the formed string.
        }

        for (int i = 0; i < v.size(); i++){

            if (v[i] == goal) return true;

        }

        return false;
    }
};


/*

generate all the n permutation of string s, 
remove first character of string s, and push it back on the back and then store it ..

now check if goal exist in this permutations, 
    return false...

*/


// without using vector to store all combinations.

class Solution {
public:

    bool rotateString(string s, string goal) {
        int n = s.length();
        string temp = s;


        while (n--){    // n baari tak loop isliye kyuki har character ko mauka diya first element banne ka ...iske baad repeat hone lagenge...
            
            char first = temp[0];   // take first character 
            temp.erase(0, 1);  // starting from the zeroth index ek element ko remove kar de..
            // ==== ki first character ko remove kar de...

            temp += first;  // append it at back

            if (temp == goal) return true;
        
        }

        return false;

    }
};


/*
generate all the n permutation of string s, 
remove first character of string s, and push it back on the back and then store it ..

now check if goal exist in this permutations, 
    return false...

but do I really need to store all the permutations, while generating the permutations I could 
check if they can become goal or not...


*/


// saap ko dekha aur tujhe dekha to pehle tujhe maarna chahiye...

class Solution {
public:

    bool rotateString(string s, string goal) {
        if (goal.length() != s.length()) return false;
        
        // kaminepan ke deewane ho gaye...
        string doubled = s + s;
        
        // If goal is a rotation of s, then goal should appear as a substring in s + s
        return doubled.find(goal) != string::npos;   
    }

};