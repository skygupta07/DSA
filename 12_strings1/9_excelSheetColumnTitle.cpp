// excelSheetColumnTitle.cpp

#include <bits/stdc++.h>
using namespace std;

/*
Given an integer columnNumber, 
return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...

Z -> 26


AA -> 27
AB -> 28 
...


 

Example 1:

Input: columnNumber = 1
Output: "A"


Example 2:

Input: columnNumber = 28
Output: "AB"


Example 3:

Input: columnNumber = 701
Output: "ZY"
 

Constraints:

1 <= columnNumber <= 2pow31 - 1

*/



class Solution {
public:
    string convertToTitle(int n) {
        string ans = ""; // String to store the resulting column title

        // Continue until there are no more digits to process
        while (n > 0) {
            // Decrement n by 1 to make it 0-indexed
            n--;

            // Calculate the remainder (0-25), representing the letter position
            int rem = n % 26;

            // Append the corresponding character ('A' + rem) to the result
            ans += ('A' + rem);

            // Update n by dividing it by 26 (move to the next higher "place")
            n /= 26;
        }

        // The result is built in reverse order, so reverse it before returning
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
