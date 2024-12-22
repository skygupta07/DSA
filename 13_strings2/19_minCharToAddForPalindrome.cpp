#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to compute the LPS array
    vector<int> computeLPS(const string& str) {
        int n = str.size();
        vector<int> lps(n, 0);
        int length = 0; // Length of the previous longest prefix suffix
        int i = 1;
    
        while (i < n) {
            if (str[i] == str[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    
        return lps;
    }
    
    // Function to find the minimum characters to add at the front
    int minChar(string& s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
    
        // Combine original string, a delimiter, and its reverse
        string combined = s + "$" + rev_s;
    
        // Compute LPS array for the combined string
        vector<int> lps = computeLPS(combined);
    
        // Minimum characters to add = length of string - length of longest palindromic prefix
        return s.size() - lps.back();
    }
};






//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends