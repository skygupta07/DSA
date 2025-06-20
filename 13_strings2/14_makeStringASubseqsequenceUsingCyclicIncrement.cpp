// makeStringASubsequenceUsingCyclicIncrement.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given two 0-indexed strings str1 and str2.

In an operation, you select a set of indices in str1, and for each index i in the set, 
increment str1[i] to the next character cyclically. 
That is 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'.

Return true if it is possible to make str2 a subsequence of str1 
by performing the operation at most once, and false otherwise.

Note: A subsequence of a string is a new string that is formed from the original string 
by deleting some (possibly none) of the characters without disturbing the relative positions
of the remaining characters. 


Example 1:

Input: str1 = "abc", str2 = "ad"
Output: true

Explanation: Select index 2 in str1.

Increment str1[2] to become 'd'. 
Hence, str1 becomes "abd" and str2 is now a subsequence. 
Therefore, true is returned.


Example 2:

Input: str1 = "zc", str2 = "ad"
Output: true

Explanation: Select indices 0 and 1 in str1. 
Increment str1[0] to become 'a'. 
Increment str1[1] to become 'd'. 
Hence, str1 becomes "ad" and str2 is now a subsequence. Therefore, true is returned.


Example 3:

Input: str1 = "ab", str2 = "d"
Output: false

Explanation: In this example, it can be shown that it is impossible to make str2 
a subsequence of str1 using the operation at most once. 

Therefore, false is returned.
 

Constraints:

1 <= str1.length <= 1e5
1 <= str2.length <= 1e5
str1 and str2 consist of only lowercase English letters.

*/


class Solution {
public:

    // Helper function to get the next character cyclically
    // 'a' -> 'b', 'b' -> 'c', ..., 'z' -> 'a'
    char nextChar(char ch) {
        return ch == 'z' ? 'a' : ch + 1;
    }

    // Main logic function: check if str2 can be made a subsequence of str1
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size(); 
        int n = str2.size(); 

        // Agar str2 ka size bada hai, to obviously impossible hai ki str2 subsquence bane str1 ka...
        if (n > m) return false;

        int i = 0;  // Pointer for str1
        int j = 0;  // Pointer for str2

        // Jab tak dono strings me valid characters bache hain
        while (i < m && j < n) {

            // Do condition check karte hain:
            // 1. str1[i] and str2[j] already same hain
            // 2. Agar str1[i] ko 1 baar increment karein (cyclically), to kya wo str2[j] ban jaata hai?
            
            if (str1[i] == str2[j] || nextChar(str1[i]) == str2[j]) {
                // Agar match ho gaya ( chahe directly ya ek increment se ), dono pointers badha do
                i++;
                j++;
            } 
            
            else {
                // Nahi mila match, to str1 me aage badh ke try karo
                i++;
            }

        }

        // Agar humne str2 ke saare characters match kara diye —> (j == n)
        // iska matlab str2 ek subsequence ban chuka hai str1 ka (after at most one cyclic increment op)
        if (j == n) return true;

        else return false;

    }
};
