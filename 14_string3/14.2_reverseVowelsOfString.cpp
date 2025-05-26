#include <bits/stdc++.h>
using namespace std;

/*

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, 
more than once.

 

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"
Output: "leotcede"

 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.


*/


class Solution {
    public:
    
        bool isVowel(char ch){
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        }
    
        string reverseVowels(string str) {
            int n = str.length();
    
            string s = str;
    
            int left = 0;
            int right = n - 1;
    
    
            while (left < right){
                char leftCh = tolower(s[left]);
                char rightCh = tolower(s[right]);
    
                if (isVowel(leftCh) && isVowel(rightCh)){
                    char temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
    
    
                    left++;
                    right--;
                }
    
                else if (! isVowel(leftCh)) left++;
                else if (! isVowel(rightCh)) right--;
            }
    
            return s;
        }
    };