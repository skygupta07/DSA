#include <bits/stdc++.h>
using namespace std;


/*

You are given a 0-indexed string s and a 0-indexed integer array spaces 
that describes the indices in the original string where spaces will be added. 
Each space should be inserted before the character at the given index.


For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], 
we place spaces before 'Y' and 'C', which are at indices 5 and 9 respectively. 
Thus, we obtain "Enjoy Your Coffee".

Return the modified string after the spaces have been added.


Example 1:

Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
Output: "Leetcode Helps Me Learn"
Explanation: 
The indices 8, 13, and 15 correspond to the underlined characters in "LeetcodeHelpsMeLearn".
We then place spaces before those characters.


Example 2:

Input: s = "icodeinpython", spaces = [1,5,7,9]
Output: "i code in py thon"
Explanation:
The indices 1, 5, 7, and 9 correspond to the underlined characters in "icodeinpython".
We then place spaces before those characters.


Example 3:

Input: s = "spacing", spaces = [0,1,2,3,4,5,6]
Output: " s p a c i n g"
Explanation:
We are also able to place spaces before the first character of the string.

*/


// pure DSA only
class Solution {
public:

    string addSpaces(string& s, vector<int>& spaces) {
        const int m = spaces.size(), n = s.length();
        string t(n + m, ' ');
        
        int j = 0; // Pointer for spaces

        for (int i = 0; i < n; i++) {
            if (j < m && i == spaces[j]) {
                t[i+j] = ' '; 
                j++;      // Move to the next space index

            }

            t[i+j]=s[i]; // Add the character from the original string
        }

        return t;
    }
};