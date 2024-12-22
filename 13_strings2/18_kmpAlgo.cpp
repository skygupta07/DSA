#include <bits/stdc++.h>
using namespace std;


class Solution { // bruteFoce will give tle
public:
    vector<int> search(string& pat, string& txt) {
        int n = txt.length();
        vector<int> ans;
        
        int k = pat.length();
        
        for (int left = 0; left <= n - k; ++left) {
            if (txt.substr(left, k) == pat) {
                ans.push_back(left);
            }
        }
        
        return ans;
    }
};


// kpm

class Solution {
public:
    vector<int> search(string& pat, string& txt) {
        int m = pat.length();
        int n = txt.length();
        vector<int> lps(m, 0); // Longest prefix suffix array
        vector<int> ans;

        // Step 1: Build the LPS array
        computeLPS(pat, m, lps);

        // Step 2: Perform the search
        int i = 0; // index for txt
        int j = 0; // index for pat
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) { // Found a match
                ans.push_back(i - j); // Store the starting index
                j = lps[j - 1]; // Reset j using LPS table
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1]; // Reset j using LPS table
                } else {
                    i++;
                }
            }
        }

        return ans;
    }

private:
    void computeLPS(string& pat, int m, vector<int>& lps) {
        int len = 0; // Length of previous longest prefix suffix
        lps[0] = 0;  // lps[0] is always 0

        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};


