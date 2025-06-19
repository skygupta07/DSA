// zigzagConversion.cpp


#include <bits/stdc++.h>
using namespace std;

/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 

(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"


Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I


Example 3:

Input: s = "A", numRows = 1
Output: "A"

*/


class Solution {
public:

    string convert(string s, int numRows) {
        
        // Edge case: agar rows sirf 1 hai, to string as-it-is return kar do
        if (numRows <= 1) return s;
        
        // Har row ke liye ek string banai gayi hai
        vector <string> v(numRows, "");  // numRows rows with empty strings

        int j = 0;      // current row index
        int dir = -1;   // direction flag: 1 -> down, -1 -> up
        
        // Har character ke liye loop chalega
        for (int i = 0; i < s.length(); i++){  

            // Zigzag pattern ka turning point: either bottom row or top row
            if (j == numRows - 1 || j == 0) dir *= -1;

            // Current character ko current row (v[j]) me daalo
            v[j] += s[i];

            // Direction ke hisaab se row index update karo

            // neeche jaa rahe ho
            if (dir == 1) j++;   
            
            // upar jaa rahe ho
            else j--;    
        }

        // Sab rows ko combine karke final result banao
        string res;

        for (auto &it : v) res += it;

        return res;
    }
};
