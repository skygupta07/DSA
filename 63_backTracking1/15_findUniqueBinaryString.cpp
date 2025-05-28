#include <bits/stdc++.h>
using namespace std;

/*

Given an array of strings nums containing n unique binary strings each of length n, 
return a binary string of length n that does not appear in nums. 
If there are multiple answers, you may return any of them.
 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.


*/

class Solution {
    public:
        // Recursive function to generate a unique binary string of length 'n'
        // while generating the different binary string check for the condition also...

        string generateUniqueBinary(int n, unordered_set <string> &st, string temp, int idx) {
            
            // Base case: If the generated string reaches the required length
            if (temp.length() == n) {
                // If this binary string is not in the given set, return it as the answer
                if (st.find(temp) == st.end()) return temp;
                return "";  // Otherwise, return an empty string (indicating failure)
            }
    
            // Try adding '0' to the current string and check
            temp += '0';
            string res = generateUniqueBinary(n, st, temp, idx + 1);
            if (!res.empty()) return res;  // If valid answer found, return immediately
    
            // Backtrack by removing last added character
            temp.pop_back();
    
            // Try adding '1' to the current string and check
            temp += '1';
            res = generateUniqueBinary(n, st, temp, idx + 1);
            if (!res.empty()) return res;  // If valid answer found, return immediately
    
            // Backtrack by removing last added character
            temp.pop_back();
    
            return "";  // If no unique string is found, return empty string
        }
    
        string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size();  // Length of binary strings
            unordered_set<string> st(nums.begin(), nums.end());  // Store given binary strings in a set for fast lookup
    
            string temp = "";
            return generateUniqueBinary(n, st, temp, 0);  // Call the recursive function
        }
    };
    