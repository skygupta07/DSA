// palindromicSubstring.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa"

*/


class Solution {
public:

        bool isPalindrome(string s, int i, int j){
            while (i<j){
                if (s[i] == s[j]){
                    i++;
                    j--;
                }
                else return false;
            }
            return true;
        }
    
        int countSubstrings(string s){ // O(n^3)
            int n = s.length();

            int count = 0;

            for (int i=0; i<n; i++){
                for (int j=i; j<n; j++){
                    if ( isPalindrome(s, i, j)) count++;
                }
            }
            return count;
        }
    };

    class Solution {
    public:

            // Helper function to count palindromes centered at (left, right)
            int palindromeCount(const string &s, int left, int right) {
                int count = 0;
        
                // Expand outward while maintaining palindrome conditions
                while (left >= 0 && right < s.length() && s[left] == s[right]) {
                    left--;   // Move left pointer to the left
                    right++;  // Move right pointer to the right
                    
                    
                    count++;  // Increment count as a valid palindrome is found
                }
        
                return count; // Return total palindrome count for this center
            }



            int countSubstrings(string s) {
                int n = s.length();
                int ans = 0;
        
                // Loop through each character in the string, considering it as a center
                for (int i = 0; i < n; i++) {

                    // Count even-length palindromes (expanding between i and i+1)
                    int even = palindromeCount(s, i, i + 1);
        
                    // Count odd-length palindromes (expanding around i)
                    int odd = palindromeCount(s, i, i);
        
                    // Add both counts to the total answer
                    ans += even + odd;
                }

                return ans;
            }
        
            
        };
        


