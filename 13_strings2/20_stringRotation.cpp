// stringsRotationsOfEachOther.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given two strings of equal lengths, s1 and s2. 
The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.


Examples :

Input: s1 = "abcd", s2 = "cdab"
Output: true

Explanation: After 2 right rotations, s1 will become equal to s2.


Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.


Input: s1 = "abcd", s2 = "acbd"
Output: false
Explanation: Strings are not rotations of each other.


Constraints:
1 <= s1.size(), s2.size() <= 1e5

*/


class Solution {
public:

    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        
        // Step 1: Check if lengths are equal
        if (s1.length() != s2.length()) return false;
        
        // Step 2: Concatenate s1 with itself 
        // tumhare kaminepan ke hum gulam ho gaye...
        string temp = s1 + s1;
        
        // Step 3: Check if s2 is a substring of temp {in syntax mai != matlab equality check hota h...}
        return temp.find(s2) != string::npos;
    }

};
