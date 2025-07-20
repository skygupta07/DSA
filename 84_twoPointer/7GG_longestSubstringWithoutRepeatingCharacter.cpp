// longestSubstringWithoutRepeatingCharacter.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.


Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 1e4
s consists of English letters, digits, symbols and spaces.

*/



// charArray 
class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int n = s.length();  // poore string ki length nikal li
        int maxLength = 0;   // yeh variable answer store karega (maximum substring length without repetition)

        // yeh vector 128 size ka bana hai kyunki ASCII character set ka size 128 hota hai
        // har character ka last seen index store karega (initially -1 mtlb kabhi dekha hi nahi)
        vector <int> charIndex(128, -1);

        int left = 0;  // sliding window ka left pointer

        // ab pura string loop se traverse karenge using right pointer
        for (int right = 0; right < n; right++) {
            
            // agar current character pehle aa chuka hai and uska last index 'left' ke aage ya equal hai
            // toh left pointer ko aage badha do
            if (charIndex[s[right]] >= left) left = charIndex[s[right]] + 1;

            // current character ka index update karo
            charIndex[s[right]] = right;

            // ab naya window length calculate karo and maxLength update karo
            maxLength = max(maxLength, right - left + 1);
        }

        // finally maxLength return karo
        return maxLength;
    }

};



// unordered_set

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int n = s.length();  // input string ka length nikal liya

        unordered_set <char> st;  // yeh set unique characters ko track karega current window ke andar

        int maxi = 0;  // yeh answer store karega (longest substring without repeating characters)

        int left = 0;  // sliding window ka left pointer

        // right pointer se string traverse karenge
        for (int right = 0; right < n; right++) {

            // agar current character s[right] already set me hai,
            // toh repeat ho gaya, toh ab tak ke characters ko remove karte jao jab tak s[right] unique na ho jaye
            if (st.count(s[right])) {

                while (st.count(s[right])) {  // jab tak repeat character hat na jaye
                    st.erase(s[left]);  // left wale character ko remove karo
                    left++;             // left pointer aage badhao
                }

                // ab current character insert karo {actually jis cheej ke liye aaye they..}
                st.insert(s[right]);  
            }

            else {
                // agar repeat nahi hai toh direct insert karo
                st.insert(s[right]);

                // ab window ka length calculate karo and maxi update karo
                maxi = max(maxi, right - left + 1);
            }

        }

        // final answer return karo
        return maxi;
    }
};




/*
using set and two pointers... left and right

right pointer ki madad se aage aage string mai iterate karte chalenge....

ek set maintain kara and while encountering a character first we check whether this character 
is already present in the set or not ... if already present means the current character is 
repetitive ... so first erase elements from the left and increment the left pointer also...

but if the character is not already present then simply insert it into the set... 
and wo global maxi (maxLength) ko to maximize karte hi rehna h...



*/



// unordered_map

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int n = s.length();            // poore string ki length nikal li
        int maxLength = 0;             // answer store karega (maximum substring length bina repeat ke)
        
        // yeh map har character ka “last seen index” store karega
        unordered_map <char, int> charMap; 
        
        // sliding window ka left pointer
        int left = 0;                 

        // ab window expand karne ke liye right pointer se poori string traverse karte hain
        for (int right = 0; right < n; right++) {

            // agar current character pehle aaya hai aur uska last seen index abhi wale window ke andar hai
            if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
                
                // yeh do conditions matlab:
                // 1) character map mai hai hi nahi → pehli baar mil raha
                // 2) map me hai par jo index stored hai, woh left se chhota hai → purane window se bahar tha
                // dono case me hum seedha current index update kar sakte hain
                charMap[s[right]] = right;
                
                // ab current valid window ka length nikal kar maxLength update karo
                maxLength = max(maxLength, right - left + 1);
            } 
            
            else {
                // yaha aane ka matlab hai duplicate character mil gaya jo abhi ke window (left..right-1) me exist karta hai
                // toh left pointer ko us previous index + 1 pe shift karo, jisse window se duplicate character hat jaaye
                left = charMap[s[right]] + 1;
                
                // ab current character ka index update karo (naya “last seen index” right)
                charMap[s[right]] = right;
            }
        }

        return maxLength;  // final answer return karo
    }
};




// unordered_set 

class Solution{
public:

    int lengthOfLongestSubstring(string s) {
        unordered_set <char> st;
        int maxLen = 0;

        int i = 0, j = 0; // Two pointers for the sliding window

        while (j < s.length()) {

            // If s[j] is unique in current window, add to set
            if (st.find(s[j]) == st.end()) {
                
                st.insert(s[j]);

                maxLen = max(maxLen, j - i + 1);

                j++; // Expand window
            } 

            else {
                // If s[j] is duplicate, remove s[i] from set and shrink window
                st.erase(s[i]);
                i++;
            }
        }

        return maxLen;
    }

};
