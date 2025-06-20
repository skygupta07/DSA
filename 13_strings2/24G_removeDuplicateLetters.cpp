// removeDuplicateLetters.cpp

/*

Given a string s, remove duplicate letters so that every letter appears once and only once.
You must make sure your result is the smallest in lexicographical order among all possible results.


Example 1:

Input: s = "bcabc"
Output: "abc"


Example 2:

Input: s = "cbacdcbc"
Output: "acdb"


Constraints:

1 <= s.length <= 10pow4
s consists of lowercase English letters.

Note: This question is the same as
1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    string removeDuplicateLetters(string s){
        int n = s.length();

        vector <int> freq(26, 0);    // Har character ka frequency count store karega
        vector <int> visited(26, 0); // Track karega ki koi character `ans` me already hai ya nahi

        string ans = ""; // Final answer ko store karega (acts like a stack)

        // Pehle har character ka frequency count calculate karo
        for (int i = 0; i < n; i++) freq[s[i] - 'a']++;

        // Ab har character ko process karo
        for (int i = 0; i < n; i++){
            
            // Current character ka frequency reduce karo
            freq[s[i] - 'a']--; 

            // Agar yeh character pehle se `ans` me hai toh ignore karo
            if (!visited[s[i] - 'a']){

                // Jab tak `ans` ka last character bada hai aur future me dubara aane wala hai

                while (ans.size() > 0 && ans.back() > s[i] && freq[ans.back() - 'a'] > 0){
                    visited[ans.back() - 'a'] = 0; // Us character ko unmark karo
                    ans.pop_back();                // Remove last character
                }
                
                // Naya character add karo
                ans += s[i];     

                // Mark karo ki yeh character `ans` me aa chuka hai
                visited[s[i] - 'a'] = 1; 
            }
        }

        return ans; // Final lexicographically smallest string return karo
    }
};



/*
 * Yeh problem ka goal hai ki ek string se duplicate letters hata kar
 * lexicographically smallest possible string return karein,
 * jisme har letter ek baar hi aaye.
 *
 * Approach:
 * 1. **Frequency Count:** Pehle ek frequency array `freq` maintain karenge jo
 *    bataayega ki har character kitni baar aaya hai.
 *
 * 2. **Visited Array:** Ek `visited` array rakhenge jo track karega ki koi
 *    character `ans` string me already hai ya nahi.
 *
 * 3. **Greedy Approach with Stack (String as Stack):**
 *    - Agar `ans` ke last character se chhota koi naya character milta hai,
 *      aur agar last character baad me dubara aane wala hai (`freq > 0`),
 *      toh usko `ans` se hata denge taki chhota lexicographical order maintain ho.
 * 
 * 
 *    - Naya character add karne se pehle check karenge ki visited hai ya nahi.
 * 
 *    - Final `ans` ko return karenge jo unique aur lexicographically smallest hoga.
 *
 * Time Complexity: **O(N)**
 * Space Complexity: **O(26) ≈ O(1)** (kyunki sirf lowercase letters hain)
 *
 */
