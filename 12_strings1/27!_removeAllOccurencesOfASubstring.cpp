// removeAllOccurrencesOfASubstring.cpp


/*
Given two strings s and part, perform the following operation on s 
until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.


Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".


Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".
 

Constraints:

1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ and part consists of lowercase English letters.

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        string result;
        int n = part.size();
        
        for (char c : s) {

            result.push_back(c);
            
            if (result.size() >= n && result.substr(result.size() - n) == part) {
                result.erase(result.size() - n);
            }
        }
        
        return result;
    }
};


class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size(); // 'part' substring ka size store kar rahe hain

        string ans; // Final result store karne ke liye ek empty string

        // String 's' ke har character ko traverse karenge
        for (char ch : s) {
            ans += ch; // Current character ko 'ans' string mein append kar rahe hain

            // Jab tak 'ans' ka size 'part' ke size se bada ya equal ho jaye aur 
            // last ke 'n' characters 'part' ke barabar ho
            if (ans.size() >= n && ans.substr(ans.size() - n) == part) {
                ans.erase(ans.size() - n); // Last 'n' characters hata denge
            }
        }

        return ans; // Final modified string return karenge
    }
};
