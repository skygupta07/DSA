// findTheIndexOfTheFirstOccurenceInAString.cpp

#include <bits/stdc++.h>
using namespace std;


/*


Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.


Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.


Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

*/


/*
substr wale method se try karte h...
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        for (int i=0; i <= m-n; i++){
            string temp = haystack.substr(i, n);
            if (temp == needle) return i;
        }
        return -1;
    }
};




class Solution {    // two loops
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        
        for (int i = 0; i <= m - n; i++) {
            int j = 0;

            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {  // it means the whole needle is present..
                return i;
            }
        }
        return -1;
    }
};