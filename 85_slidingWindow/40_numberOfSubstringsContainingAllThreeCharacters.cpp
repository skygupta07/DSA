// numberOfSubstringsContainingAllThreeCharacters.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c 
are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters
 a, b and c are "aaacb", "aacb" and "acb". 

Example 3:

Input: s = "abc"
Output: 1
 
Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.

*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();  // Step 1: String ka length store kar liya

        // Step 2: freq[0] -> 'a', freq[1] -> 'b', freq[2] -> 'c' ka count
        // Initialize frequency array for 'a', 'b', 'c' with 0
        vector<int> freq(3, 0);

        int left = 0;   // Sliding window ka left pointer
        int count = 0;  // Final answer, number of valid substrings

        // Step 3: Right pointer se string traverse karte jaa rahe hain
        for (int right = 0; right < n; right++) {
            
            // Current character ka frequency badha do
            // Example: s[right] = 'c' => 'c' - 'a' = 2 => freq[2]++
            freq[s[right] - 'a']++;  

            // Step 4: Jab tak window ke andar 'a', 'b', 'c' teeno present hain
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // Abhi ke right index tak ke saare substrings starting from 'left' are valid
                // Example: agar n = 10, right = 5 => substrings: [left...5], [left...6], ... [left...9] are all valid
                // Isiliye (n - right) substrings valid hain
                count += (n - right);

                // Window ko chhota karo by removing s[left]
                // jisse aur naye window explore ho sake
                freq[s[left] - 'a']--;

                // Left pointer ko aage badha diya (window shrink kiya)
                left++;
            }
        }

        // Step 5: Final answer return kar do
        return count;
    }
};
