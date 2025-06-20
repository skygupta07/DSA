// stringAddSpaces.cpp

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

    string addSpaces(string &s, vector<int>& spaces) {
        
        const int m = spaces.size();   // number of spaces to insert
        const int n = s.length();      // original string length

        // Final result string ka size n + m hoga, kyunki m spaces insert karne hain
        string res(n + m, ' ');  // initially sab ' ' se bhar diya, baad me characters set karenge

        // `spaces` vector ka pointer - kis index pe space daalna hai, uska track rakhega
        int j = 0;

        // i => original string `s` ka index
        for (int i = 0; i < n; i++) {

            // Jab tak aur space insert karne hain, aur agar current index i matches
            // space index j (i.e., space insert karna hai is position pe)

            if (j < m && i == spaces[j]) {
                res[i + j] = ' ';  // shift ho chuka hai res ka index (i+j), waha space daal diya

                j++;  // next space index pe move kar jao
            }

            // res[i + j] mein original string ka character daal rahe hain
            // i+j isliye because `j` spaces ab tak insert ho chuki hain, so shift hua index

            res[i + j] = s[i];
        }

        // final string return karo with spaces inserted
        return res; 

    }
};
