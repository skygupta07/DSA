#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumDeletions(string s) {
        const int n = s.size();
        vector <int> B_pref(n);     // integer value hi store karenge...
        vector <int> A_suff(n);

        // fill pref array
        B_pref[0] = (s[0] == 'b');  // threshold
        A_suff[n-1] = (s[n-1] == 'a');  // threshold

        // fill B_pref array..

        for (int i=1; i<=n-1; i++){
            B_pref[i] = B_pref[i-1] + (s[i] == 'b');
        }

        // fill A_suff array..
        for (int i=n-2; i>=0; i--){
            A_suff[i] = A_suff[i+1] + (s[i] == 'a');
        }

        int mini = INT_MAX;

        for (int i=0; i<n; i++){
            mini = min(mini , B_pref[i] + A_suff[i] - 1);   // same hi cheej do baar count ho rahi thi ....isliye ek baar ghata diya..
        }

        return mini;

    }
};