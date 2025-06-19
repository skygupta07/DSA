// deleteCharactersToMakeFancyString.cpp

#include <bits/stdc++.h>
using namespace std;

/*

A fancy string is a string where no three consecutive characters are equal.
Given a string s, delete the minimum possible number of characters from s to make it fancy.
Return the final string after the deletion. It can be shown that the answer will always be unique.


Example 1:

Input: s = "leeetcode"
Output: "leetcode"

Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".


Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".


Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.

*/


class Solution {
public:

    string makeFancyString(string s) {
        // Final string store karne ke liye
        string ans = "";

        // Pehla character to hamesha allow hoga, isliye direct daal diya
        ans.push_back(s[0]);  // "threshold" means starting point bana liya

        int n = s.size();
        int cnt = 1;  // ek character to daal hi chuke hain, to count 1 se start hoga

        // Loop start karenge second character se (i = 1), kyunki pehla to already ans me hai
        for (int i = 1; i < n; i++) {
            
            // Agar current character, ans ke last character ke barabar hai
            if (s[i] == ans.back()) {  
                cnt++;  // count badhao, same character mila to
                if (cnt < 3) 
                    ans.push_back(s[i]);  // agar 3 se kam bar aaya hai to add karo
                // agar 3 ya usse zyada ho gaya to skip kar dena (do hi allowed hain)
            }

            else {
                // agar different character mila to count reset karo
                cnt = 1;
                ans.push_back(s[i]);  // naye character ko add karo
            }
        }

        // Modified string return karo
        return ans;
    }
};
