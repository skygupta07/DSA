// minimumCharactersToAddToMakeStringPalindrome


/*

Given a string S, the task is to find the minimum number of characters that need to be added 
at the beginning of the string to make it a palindrome.

You are allowed to add only characters at the front of the string (not at the end or in the middle).


Example:

Input:
3

abc
aacecaaa
abcd

Output:

2
0
3

Explanation:

For "abc" → Add "cb" in front → "cbabc" is a palindrome. So, answer is 2.
For "aacecaaa" → It is already a palindrome. So, answer is 0.
For "abcd" → Add "dcb" in front → "dcbabcd" is a palindrome. So, answer is 3.


Constraints:
1 <= |S| <= 10^5

String contains only lowercase English alphabets.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // KMP algorithm ka part – LPS array calculate karna
    vector <int> computeLPS(const string &str) {
        int n = str.size();
        vector <int> lps(n, 0); // LPS[i] stores the length of the longest prefix which is also suffix ending at i
        
        int length = 0; // Length of the previous longest prefix suffix
        int i = 1;

        while (i < n) {

            if (str[i] == str[length]) {
                length++;

                lps[i] = length;
                i++;
            } 
            
            else {
                // If mismatch and length > 0, toh previous LPS check karo
                if (length != 0) {
                    length = lps[length - 1]; // jump back
                } 
                
                else {
                    // No prefix match at all
                    lps[i] = 0;
                    i++;
                }

            }
        }

        return lps;
    }
    
    // Main function to calculate minimum characters to be added at front
    int minChar(string &s) {
        
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end()); // s ka reverse le liya

        // Combine: original + delimiter + reverse
        string combined = s + "$" + rev_s;

        // LPS of combined string nikal rahe (KMP preprocessing)
        vector <int> lps = computeLPS(combined);

        // Palindromic prefix ki length = lps.back()
        // To make the whole string palindrome from front: totalLength - matchedPrefix
        return s.size() - lps.back();

    }

};


/*

Intuition:

Agar hume ek string ko palindrome banana hai by adding minimum characters only at the front, toh hume bas yeh dekhna hai ki kitna part string ka already palindromic prefix hai.
Jo remaining part hai, uska reverse hume front mein add karna padega.

Algorithm:

Reverse the string s and call it rev_s.

Create a combined string: s + "$" + rev_s

(Dollar sign $ is a unique delimiter to avoid overlap/confusion during LPS).

Compute the LPS (Longest Prefix Suffix) array for this combined string.

Last value of LPS tells us kitna prefix s ka already palindrome ban raha hai.
minCharsToAdd = s.length() - lps.back()

*/

