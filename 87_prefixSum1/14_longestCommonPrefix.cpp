#include <bits/stdc++.h>
using namespace std;

/*

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".


Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"


Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.


*/

class Solution{
public:

    string longestCommonPrefix(vector<string> &v){
        string ans = "";
        sort(v.begin(), v.end()); // sorting the string lexicographically...

        int n = v.size();
        string first = v[0];
        string last = v[n - 1];

        // agar equal elements sach mai honge to pehle aur last strings se hi pta lag jaega...
        for (int i = 0; i < min(first.size(), last.size()); i++){

            // jiss moment par hi unke character differ kar gaye wahi par answer return kar de..
            if (first[i] != last[i]) return ans;
            
            ans += first[i];
        }

        return ans;
    }
};