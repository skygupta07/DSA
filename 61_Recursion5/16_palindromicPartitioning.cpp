// palindromicPartitioning.cpp

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



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while (i < j){
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    void f(int i, string s, vector <string> &path, vector<vector<string>> &res){
        int n = s.length();

        if (i == n){
            res.push_back(path);
            return; // imp
        }

        // accha ye for loop isliye lag rahe h kyuki bhaiya tu har index pe partitioning ka try karega na saale...
        for (int j=i; j<n; j++){

            if (isPalindrome(s, i, j)){

                path.push_back(s.substr(i, j-i+1));
                f(j+1, s, path, res);   // call for next index of jisne pehle partitioning 
                // karwayi thi...
                path.pop_back();    // backtracking
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector <string> path;   // yes better rahega ki path bhi paas karo...
        vector<vector<string>> res;

        // idx, string , path, res
        f(0, s, path, res);

        return res;
    }
};


/*
try partitioning at each index 
if partitioning at ith index generates the palindrome string then do it recursively
for the next index starting from i+1 to n-1 index as well...


base case : 
     if (j == n-1) res.push_back(path);

*/