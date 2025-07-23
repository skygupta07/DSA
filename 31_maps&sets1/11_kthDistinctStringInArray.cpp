// kthDistinctStringInArray.cpp

#include <bits/stdc++.h>
using namespace std;


/*

A distinct string is a string that is present only once in an array.

Given an array of strings arr, and an integer k, return the kth distinct string present in arr. 
If there are fewer than k distinct strings, return an empty string "".

Note that the strings are considered in the order in which they appear in the array.
 

Exafreqle 1:

Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"

Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 


Exafreqle 2:

Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"

Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.


Exafreqle 3:

Input: arr = ["a","b","a"], k = 3
Output: ""

Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, 
we return an efreqty string "".
 

Constraints:

1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.

*/


class Solution {
public:

    string kthDistinct(vector <string> &arr, int k) {

        int n = arr.size();
        vector <string> unique;

        // ye unordered_map ka use frequency ke liye kucch jyada nahi kiya jaa rha h...
        // ha yrr sach mai bahut jyada hi use kar rahe h....
        unordered_map <string, int> freq;

        for (auto str : arr) freq[str]++;
        

        // map ne jaise marji store kar rakha ho ... koi nahi mai to acche se hi line wise dekhunga...

        for (const auto &str : arr) {

            if (freq[str] == 1) {
                unique.push_back(str);
            }
            
        }

        if (k > unique.size()) return "";

        return unique[k-1];
    }
    
};