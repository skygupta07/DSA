#include <bits/stdc++.h>
using namespace std;

/*
An additive number is a string whose digits can form an additive sequence.

A valid additive sequence should contain at least three numbers. 
Except for the first two numbers, each subsequent number in the sequence 
must be the sum of the preceding two.

Given a string containing only digits, return true if it is an additive number or false otherwise.

Note: Numbers in the additive sequence cannot have leading zeros, 
so sequence 1, 2, 03 or 1, 02, 3 is invalid.


Example 1:

Input: "112358"
Output: true
Explanation: 
The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8


Example 2:

Input: "199100199"
Output: true
Explanation: 
The additive sequence is: 1, 99, 100, 199. 
1 + 99 = 100, 99 + 100 = 199

*/

class Solution {
public:
    vector<long long int> ans; // Ye resultant vector hai jo additive sequence store karega

    // Ye helper function hai jo backtracking perform karega
    bool backtrack(string s, int start) {  
        // Agar pura string traverse ho gaya aur kam se kam 3 numbers mil gaye, to true return karenge
        if (start == s.size() && ans.size() > 2) return true;  

        unsigned long long n = 0; // Naya number banane ke liye variable

        // String ko traverse karna start karenge given index se
        for (int i = start; i < s.size(); i++) { 
            n = n * 10 + (s[i] - '0');  // Naya number form kar rahe hain

            // Agar number negative ho gaya ya out of bound chala gaya to false return karenge
            if (n < 0 || n > ULLONG_MAX) return false;  

            // Agar vector me 2 ya usse zyada elements hain aur current number previous two numbers ka sum ke barabar hai
            if (ans.size() < 2 || (long long)ans.back() + (long long)ans[ans.size() - 2] == n) { 
                ans.push_back(n); // Naya number add karenge sequence me
                
                // Backtracking call karenge agle index se, agar valid sequence mili to true return karenge
                if (backtrack(s, i + 1)) return true;  
                
                // Agar condition satisfy nahi hoti to backtrack karke previous state par wapas aayenge
                ans.pop_back();  // backtrack
            }

            // Agar leading zero mila (jaise "05") to aage check karna bekaar hai, false return karenge
            if (s[i] == '0' && i == start) return false;  
        }

        return false; // Agar koi valid sequence nahi mili to false return karenge
    }

    // Ye main function hai jo string ko check karega ki wo additive number hai ya nahi
    bool isAdditiveNumber(string s) {  
        return backtrack(s, 0); // Backtracking function ko call karenge
    }
};
