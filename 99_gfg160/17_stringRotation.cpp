#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Step 1: Check if lengths are equal
        if (s1.length() != s2.length())
            return false;
        
        // Step 2: Concatenate s1 with itself
        string temp = s1 + s1;
        
        // Step 3: Check if s2 is a substring of temp
        return temp.find(s2) != string::npos;
    }
};
