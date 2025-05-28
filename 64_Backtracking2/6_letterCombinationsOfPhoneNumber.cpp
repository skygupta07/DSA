// asked in OA

// letterCombinationsOfPhoneNumber
#include <bits/stdc++.h>
using namespace std;

/*

Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/



// Approach: Backtracking

class Solution {
    public:
    
        void solve(string digits, vector <string> &ans, vector <string> pad, string temp, int idx){
            
            if (idx == digits.size()){ // issey two (digit ki length) lengths se combinations banenge..
                ans.push_back(temp);
                return; //imp
            }
    
            // uss button pe kya value h
            /*
            digits - string
            idx - integer

            digits[idx] -> character 
            '0' - character jisko agar ghata diya character se to number ban jayega...ans

            digits[idx] - '0' -> integer

            pad[digits[idx] - '0'] -> string aayega...
            
            */



            string value = pad[digits[idx]-'0'];
            
            // exploring all possibilities...
            for (char ch : value){
                temp.push_back(ch);

                solve(digits, ans, pad, temp, idx+1);
                
                // backtrack..
                temp.pop_back();
            }
        }
    
    
        vector <string> letterCombinations(string digits) {
            if (digits.size() == 0) return {}; // base case
            vector <string> ans; 
    
            // chalaki kari pehle do 0 aur 1 button kahli chhod diye.. ye east campus wale bande ne trick batayi thi..
            vector <string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
    
            solve(digits, ans, pad, "", 0);
            return ans;
        }
    };