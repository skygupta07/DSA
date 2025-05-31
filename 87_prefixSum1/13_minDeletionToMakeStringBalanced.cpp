#include <bits/stdc++.h>
using namespace std;

/*

You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. 
s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.


Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").


Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.
 

Constraints:

1 <= s.length <= 105
s[i] is 'a' or 'b'​​.


*/



class Solution {
public:
    int minimumDeletions(string s){
        const int n = s.size();

        // isss question mai interesting solve kiya h ....a tere pehle chahiye they but bc mene uska suff array banaya h..
        vector <int> BPref(n);     // integer value hi store karenge...
        vector <int> ASuff(n);

        // fill pref array
        BPref[0] = (s[0] == 'b');  // threshold
        ASuff[n-1] = (s[n-1] == 'a');  // threshold

        // fill BPref array..

        for (int i=1; i < n; i++){
            BPref[i] = BPref[i-1] + (s[i] == 'b');
        }

        // fill ASuff array..
        for (int i=n-2; i>=0; i--){
            ASuff[i] = ASuff[i+1] + (s[i] == 'a');
        }

        int mini = INT_MAX;

        for (int i=0; i<n; i++){
            mini = min(mini , BPref[i] + ASuff[i] - 1);   // same hi cheej do baar count ho rahi thi ....isliye ek baar ghata diya..
        }

        return mini;

    }
};