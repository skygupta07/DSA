// palindromePartitioning1.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s. 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]


Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

*/



class Solution {
private:
    // Check if a substring s[start:end] is a palindrome
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    // Recursive function to generate all palindrome partitions
    void partition(const string& s, int start, vector<string>& par, vector<vector<string>>& pars) {
        int n = s.length();
        if (start == n) {
            pars.push_back(par);
            return;
        }

        for (int i = start; i < n; i++) {
            if (isPalindrome(s, start, i)) {
                par.push_back(s.substr(start, i - start + 1));
                partition(s, i + 1, par, pars);
                par.pop_back();  // backtrack to explore other partitions
            }
        }
    }

public:
    // Main function to initiate the partitioning
    vector<vector<string>> partition(string s) {
        vector<vector<string>> pars;
        vector<string> par;
        partition(s, 0, par, pars);
        return pars;
    }
};