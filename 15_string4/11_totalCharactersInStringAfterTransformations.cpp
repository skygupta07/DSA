// totalCharactersInStringAfterTransformations1.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given a string s and an integer t, representing the number of transformations to perform. 
In one transformation, every character in s is replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. 
For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.

Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.


Example 1:

Input: s = "abcyy", t = 2

Output: 7

Explanation:

First Transformation (t = 1):

'a' becomes 'b'
'b' becomes 'c'
'c' becomes 'd'
'y' becomes 'z'
'y' becomes 'z'

String after the first transformation: "bcdzz"

Second Transformation (t = 2):
'b' becomes 'c'
'c' becomes 'd'
'd' becomes 'e'
'z' becomes "ab"
'z' becomes "ab"

String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.


Example 2:

Input: s = "azbk", t = 1

Output: 5

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'z' becomes "ab"
'b' becomes 'c'
'k' becomes 'l'

String after the first transformation: "babcl"
Final Length of the string: The string is "babcl", which has 5 characters.
 

Constraints:


1 <= s.length <= 1e5
s consists only of lowercase English letters.
1 <= t <= 1e5

*/


class Solution {
public:
    const int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        // Step 1: Character frequency count (0 to 25 represents 'a' to 'z')
        // cnt[i] = how many times character ('a' + i) is present in current string
        vector <long long> cnt(26, 0);

        // Count frequency of each character in initial string
        for (char ch : s) cnt[ch - 'a']++;

        // Step 2: Perform transformations t times
        for (int j = 0; j < t; j++) {

            vector <long long> temp(26, 0); // temp array to store transformed frequencies

            for (int i = 0; i < 26; i++) {
                
                if (i == 25) {
                    // Agar current character is 'z' (i.e. index 25), then:
                    // 'z' → "ab", i.e. 1 char goes to 'a' (index 0) and 1 to 'b' (index 1)
                    temp[0] = (temp[0] + cnt[i]) % mod;
                    temp[1] = (temp[1] + cnt[i]) % mod;
                } 

                else {
                    // Otherwise, character increments normally: 'a' → 'b', 'b' → 'c', ..., 'y' → 'z'
                    temp[i + 1] = (temp[i + 1] + cnt[i]) % mod;
                }
                
            }

            // Update cnt to new transformed frequencies for next round
            cnt = temp;
        }

        // Step 3: Sum all character frequencies to get final string length
        long long len = 0;
        
        for (long long ch : cnt) len = (len + ch) % mod;

        return len;
    }
    
};
